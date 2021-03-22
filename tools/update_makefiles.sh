#!/bin/bash

# extract folder name containing file
#
# param ${1} file name
# return folder name
extract_folder_name() {
	# return name of the file until last '/'
	echo "$(echo "${1}" | rev | cut -d '/' -f 2- | rev)"
}

# extract all includes found in source files found in the same folder as specified Makefile.am
#
# param ${1} path to a Makefile.am
# return all dependencies libs in the order of compilation
extract_includes() {
	# extract folder name from current library Makefile.am
	CURRENT_FOLDER=$(extract_folder_name "${1}")"/"
	# select only files in current folder
	SEARCH_FILES=$(echo "${FILE_LIST}" | grep "${CURRENT_FOLDER}")
	# select all lines containing '#include ' directive
	RAW_INCLUDES_LIST=$(echo "${SEARCH_FILES}" | xargs grep "^#include " 2>/dev/null)
	# filter only included dependencies found in other libraries by using the form 'other_lib_name/header_file.h'
	# to do this it is required to select the string between '<' and '>', searching for '/' character and returning the name until last '/'
	RAW_INCLUDES_LIST=$(echo "${RAW_INCLUDES_LIST}" | cut -d "#" -f 2 | tr "\"" " " | cut -d "<" -f 2 | cut -d ">" -f 1 | grep "\/" | rev | cut -d "/" -f 2 | rev | sort | uniq)
	# filter includes that are not compiled by the project's Makefiles
	INCLUDES_LIST=
	for i in ${LIBRARIES_LIST}; do
		for j in ${RAW_INCLUDES_LIST}; do
			if test "${j}" = "${i}"; then
				INCLUDES_LIST="${i} ${INCLUDES_LIST}"
				break
			fi
		done
	done
	# remove empty spaces
	INCLUDES_LIST=$(echo ${INCLUDES_LIST} | tr -s " ")
	# order dependencies in the order of compilation
	FILTERED_INCLUDES_LIST=
	for i in ${LIBRARIES_LIST}; do
		if test $(echo "${INCLUDES_LIST}" | grep "\b${i}\b" | wc -l) -ne 0; then
			FILTERED_INCLUDES_LIST="${i} ${FILTERED_INCLUDES_LIST}"
		fi
	done
	echo "${FILTERED_INCLUDES_LIST}"
}

# extract all header only files and headers and source files found in the external library required by specified library
# param ${1} name of the current library
# param ${2} name of the external dependency library required by current library
# return the list of header only files as 'HEADERS: heaser1.h header2.h' and header and source files as 'HEADERS_AND_SOURCES: source1.h source1.cc source2.h source2.cpp'
extract_non_include_files() {
	# extract folder name for current library Makefile.am
	CURRENT_FOLDER=$(extract_folder_name "src/lib/${1}/Makefile.am")"/"
	# extract folder name for external dependency library Makefile.am
	EXTERNAL_FOLDER=$(extract_folder_name "src/lib/${2}/Makefile.am")"/"
	# select only files in current folder
	SEARCH_FILES=$(echo "${FILE_LIST}" | grep "${CURRENT_FOLDER}")
	HEADERS_LIST=
	NON_HEADERS_LIST=
	# select all lines containing '#include ' directive
	RAW_INCLUDES_LIST=$(echo "${SEARCH_FILES}" | xargs grep "^#include " 2>/dev/null)
	# filter only included headers found in other libraries by using the form 'other_lib_name/header_file.h'
	# to do this it is required to select the string between '<' and '>', searching for '/' character, search for the extension marker '.' and returning the name after last '/'
	RAW_INCLUDES_LIST=$(echo "${RAW_INCLUDES_LIST}" | cut -d "#" -f 2 | tr "\"" " " | cut -d "<" -f 2 | cut -d ">" -f 1 | grep "\/" | grep "\b${2}\b" | cut -d "/" -f 2 | grep "\." | sort | uniq)
	# select only files in dependency library folder and strip full path
	RELATIVE_SEARCH_FILES=$(echo "${FILE_LIST}" | grep "${EXTERNAL_FOLDER}" | sed -e "s#${REPO_FOLDER}${EXTERNAL_FOLDER}##g")
	# search for the header file but also for source files
	for i in ${RAW_INCLUDES_LIST}; do
		# filter by name only (no extension)
		FILTER=$(echo "${i}" | cut -d "." -f 1)
		# filter non header files with exact name of the header file without the extension
		NON_HEADER=$(echo "${RELATIVE_SEARCH_FILES}" | grep "\b${FILTER}\." | grep -v "${i}")
		if test $(echo "${NON_HEADER}" | wc -w) -ne 0; then
			# append header and source file names
			NON_HEADERS_LIST="${i} ${NON_HEADER} ${NON_HEADERS_LIST}"
		else
			# append header only file name
			HEADERS_LIST="${i} ${HEADERS_LIST}"
		fi
	done
	# sort header only files
	HEADERS_LIST=$(echo ${HEADERS_LIST} | tr -s " " | sort | uniq)
	# sort header and source files
	NON_HEADERS_LIST=$(echo ${NON_HEADERS_LIST} | tr -s " " | sort | uniq)
	echo "HEADERS_AND_SOURCES:${NON_HEADERS_LIST}"
	echo "HEADERS:${HEADERS_LIST}"
}

# extract all valid dependencies of a specified library
#
# param ${1} list of all libraries in the reverse compilation order
# param ${2} library name for which the dependency list is computed
# return the list of dependencies for specified library in the reverse compilation order 
extract_dependencies() {
	echo "${1}" | grep -Eo "\b${2}\b.*$"
}

# extract computed dependency for specified library
#
# param ${1} library name for which the dependency list is retrieved
# return stored value of computed dependencies or 'NONE' if dependencies have not been computed yet
extract_computed_dependencies() {
	NAME="COMPUTED_DEPENDENCIES_${1}"
	if test -n "${!NAME+x}"; then
		echo "${!NAME}"
	else
		echo "NONE"
	fi
}

# if wrong number of parameters print usage
if test ${#} -ne 1; then
	echo "Usage: ${0} path/to/kea/repo"
	exit
fi

# folder containing full repo
REPO_FOLDER=${1}

# filter all Makefile.am files
MAKEFILES_LIST=$(find ${REPO_FOLDER} | grep "Makefile\.am" | grep "src\/" | sort)

# if no Makefile.am found exit
if test -z "${MAKEFILES_LIST}"; then
	echo "invalid repo path: no Makefile.am file found"
	exit
fi

echo "list of Makefile.am:"
echo "${MAKEFILES_LIST}"

# base Makefile.am for all sources is in src/lib/Makefile.am
BASE_MAKEFILE=$(echo "${MAKEFILES_LIST}" | grep "src\/lib\/Makefile.am")

# if no src/lib/Makefile.am found exit
if test -z ${BASE_MAKEFILE}; then
	echo "invalid repo path: no src/lib/Makefile.am file found"
	exit
fi

echo "base Makefile.am:"
echo "${BASE_MAKEFILE}"

# generate the list of libraries in the compilation order
LIBRARIES_LIST=
RAW_LIBRARIES_LIST=$(cat "${BASE_MAKEFILE}" | grep "SUBDIRS")
for i in ${RAW_LIBRARIES_LIST}; do
	LIBRARIES_LIST="${LIBRARIES_LIST} $(echo ${i} | grep -v "SUBDIRS" | grep -v '=')"
done

# remove empty spaces
LIBRARIES_LIST=$(echo "${LIBRARIES_LIST}" | tr -s ' ' | xargs)

# generate the list of libraries in the reverse compilation order
REVERSE_LIBRARIES_LIST=
for i in ${LIBRARIES_LIST}; do
	REVERSE_LIBRARIES_LIST="${i} ${REVERSE_LIBRARIES_LIST}"
done

echo "list of libraries:"
echo "${LIBRARIES_LIST}"

echo "reverse list of libraries:"
echo "${REVERSE_LIBRARIES_LIST}"

# filter all files of interest ignoring irrelevant ones
# ignore .git, .libs, .deps doc folders and .o .lo .Plo .Po .gcno .gcda .m4 .dox .json .mes files
FILE_LIST=$(find "${REPO_FOLDER}" 2>/dev/null | grep -v "\.git" | grep -v "\/\.libs\/" | grep -v "\.o$" | grep -v "\/\.deps\/" | grep -v "\.lo$" | grep -v "\.Plo$" | grep -v "\.Po$" | grep -v "\.gcno$" | grep -v "gcda" | grep -v "\.m4$" | grep -v "\.dox$" | grep -v "\.json$" | grep -v "\/doc\/" | grep -v "\.mes$" | sort)

#echo "files:"
#echo "${FILE_LIST}"

# generate the list of dependencies for all libraries in src/lib
for i in ${LIBRARIES_LIST}; do
	# generate current library Makefile.am path
	BASE_LIBRARIES_MAKEFILES="${BASE_LIBRARIES_MAKEFILES} src/lib/${i}/Makefile.am"
	# extract dependencies found in the library folder
	BASE_DEPENDENCIES=$(extract_includes "src/lib/${i}/Makefile.am" "${i}")
	# generate the list of valid dependencies for the current librabry (that compilation order into account)
	VALID_LIST=$(extract_dependencies "${REVERSE_LIBRARIES_LIST}" "${i}")
	# detect dependencies errors by searching for dependencies that are compiled after the current library and can generate missing symbols
	NON_RECURSIVE_BASE_DEPENDENCIES=
	for j in ${BASE_DEPENDENCIES}; do
		# only add the dependency if it is in the valid dependencies list to prevent infinite recursion and log the error otherwise
		if test $(echo "${VALID_LIST}" | grep "\b${j}\b" | wc -l) -eq 0; then
			# search for external header and source files
			INVALID_EXTERNAL_DEPENDENCIES=$(extract_non_include_files "${i}" "${j}")
			# filter header only external files
			EXTERNAL_HEADERS=$(echo "${INVALID_EXTERNAL_DEPENDENCIES}" | grep "HEADERS:" | cut -d ":" -f 2)
			# filter header and source external files
			EXTERNAL_ALL=$(echo "${INVALID_EXTERNAL_DEPENDENCIES}" | grep "HEADERS_AND_SOURCES:" | cut -d ":" -f 2)
			echo "### ERROR ### dependencies ERROR for ${i} on ${j} with:"
			# if there are any header only external files
			if test $(echo "${EXTERNAL_ALL}" | wc -w) -ne 0; then
				echo "non header files: ${EXTERNAL_ALL}"
			fi
			# if there are any header and source external files
			if test $(echo "${EXTERNAL_HEADERS}" | wc -w) -ne 0; then
				echo "only header files: ${EXTERNAL_HEADERS}"
			fi
		else
			# don't add current library to it's dependencies list
			if test ${j} != ${i}; then
				NON_RECURSIVE_BASE_DEPENDENCIES="${NON_RECURSIVE_BASE_DEPENDENCIES} ${j}"
			fi
		fi
	done
	# all found dependencies in the reverse compilation order
	BASE_DEPENDENCIES=$(echo "${BASE_DEPENDENCIES}" | xargs)
	# all found and valid dependencies in the reverse compilation order
	NON_RECURSIVE_BASE_DEPENDENCIES=$(echo "${NON_RECURSIVE_BASE_DEPENDENCIES}" | xargs)
	echo "${i} base dependencies:"
	echo "${BASE_DEPENDENCIES}"
	echo "${i} non recursive dependencies:"
	echo "${NON_RECURSIVE_BASE_DEPENDENCIES}"
	# all valid dependencies that can be added by each dependency library
	DEPENDENCIES=
	for j in ${NON_RECURSIVE_BASE_DEPENDENCIES}; do
		NEW_DEPENDENCIES=$(extract_computed_dependencies "${j}")
		if test "${NEW_DEPENDENCIES}" == "NONE"; then
			echo "### ERROR ### computed dependency not found for ${j}"
		else
			DEPENDENCIES="${NEW_DEPENDENCIES} ${DEPENDENCIES}"
		fi
	done
	DEPENDENCIES=$(echo "${DEPENDENCIES} ${NON_RECURSIVE_BASE_DEPENDENCIES}" | tr -s " " "\n" | sort | uniq | xargs)
	echo "${i} dependencies:"
	echo "${DEPENDENCIES}"
	# order dependencies in the order of compilation
	SORTED_DEPENDENCIES=
	for j in ${LIBRARIES_LIST}; do
		if test $(echo "${DEPENDENCIES}" | grep "\b${j}\b" | wc -l) -ne 0; then
			SORTED_DEPENDENCIES="${j} ${SORTED_DEPENDENCIES}"
		fi
	done
	echo "${i} sorted dependencies:"
	echo "${SORTED_DEPENDENCIES}"
	declare COMPUTED_DEPENDENCIES_${i}="${SORTED_DEPENDENCIES}"

	# todo: only extent with dependencies that each dependency asks for, not all possible dependencies
done

echo "base Makefiles.am:"
echo "${BASE_LIBRARIES_MAKEFILES}"

# todo: continue with Makefile.am that are not in src/lib folder

exit

