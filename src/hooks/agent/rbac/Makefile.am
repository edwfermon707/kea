SUBDIRS = . libloadtests tests

AM_CPPFLAGS  = -I$(top_builddir)/src/lib -I$(top_srcdir)/src/lib
AM_CPPFLAGS += $(BOOST_INCLUDES)
AM_CXXFLAGS  = $(KEA_CXXFLAGS)

# Ensure that the message file and doxygen file is included in the distribution
EXTRA_DIST = rbac_messages.mes
EXTRA_DIST += rbac.dox

CLEANFILES = *.gcno *.gcda

# convenience archive

noinst_LTLIBRARIES = librbac.la

librbac_la_SOURCES  = rbac.cc rbac.h
librbac_la_SOURCES += rbac_api.h rbac_api.cc
librbac_la_SOURCES += rbac_role.h
librbac_la_SOURCES += rbac_acl.h
librbac_la_SOURCES += rbac_response_filter.h rbac_response_filter.cc
librbac_la_SOURCES += rbac_log.cc rbac_log.h
librbac_la_SOURCES += rbac_messages.cc rbac_messages.h
librbac_la_SOURCES += version.cc

librbac_la_CXXFLAGS = $(AM_CXXFLAGS)
librbac_la_CPPFLAGS = $(AM_CPPFLAGS)

# install the shared object into $(libdir)/kea/hooks
lib_hooksdir = $(libdir)/kea/hooks
lib_hooks_LTLIBRARIES = libca_rbac.la

libca_rbac_la_SOURCES  =
libca_rbac_la_LDFLAGS  = $(AM_LDFLAGS)
libca_rbac_la_LDFLAGS  += -avoid-version -export-dynamic -module
libca_rbac_la_LIBADD = librbac.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/process/libkea-process.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/http/libkea-http.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/hooks/libkea-hooks.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/cc/libkea-cc.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/cryptolink/libkea-cryptolink.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/log/libkea-log.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/util/libkea-util.la
libca_rbac_la_LIBADD += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
libca_rbac_la_LIBADD += $(LOG4CPLUS_LIBS)
libca_rbac_la_LIBADD += $(CRYPTO_LIBS)
libca_rbac_la_LIBADD += $(BOOST_LIBS)

# If we want to get rid of all generated messages files, we need to use
# make maintainer-clean. The proper way to introduce custom commands for
# that operation is to define maintainer-clean-local target. However,
# make maintainer-clean also removes Makefile, so running configure script
# is required.  To make it easy to rebuild messages without going through
# reconfigure, a new target messages-clean has been added.
maintainer-clean-local:
	rm -f rbac_messages.h rbac_messages.cc

# To regenerate messages files, one can do:
#
# make messages-clean
# make messages
#
# This is needed only when a .mes file is modified.
messages-clean: maintainer-clean-local

if GENERATE_MESSAGES

# Define rule to build logging source files from message file
messages: rbac_messages.h rbac_messages.cc
	@echo Message files regenerated

rbac_messages.h rbac_messages.cc: rbac_messages.mes
	$(top_builddir)/src/lib/log/compiler/kea-msg-compiler $(top_srcdir)/src/hooks/agent/rbac/rbac_messages.mes

else

messages rbac_messages.h rbac_messages.cc:
	@echo Messages generation disabled. Configure with --enable-generate-messages to enable it.

endif
