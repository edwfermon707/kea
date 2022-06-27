# -*- coding: utf-8 -*-
#
# Configuration file for the Sphinx documentation builder.
#
# This file does only contain a selection of the most common options. For a
# full list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))

# to avoid "sphinx.errors.SphinxParallelError: RecursionError: maximum recursion depth exceeded while pickling an object"
import sys
sys.setrecursionlimit(5000)

# -- Project information -----------------------------------------------------

project = 'Kea'
copyright = '2019-2020, Internet Systems Consortium'
author = 'Internet Systems Consortium'

# get current kea version
config_ac_path = '../../configure.ac'
changelog_path = '../../ChangeLog'
release = 'UNRELEASED'
with open(config_ac_path) as f:
    for line in f.readlines():
        if line.startswith('AC_INIT(kea'):
            parts = line.split(',')
            release = parts[1]
            # If the first line of the ChangeLog announces release, it means
            # that this is the final release.
            dash_parts = release.split('-')
            candidate_release = dash_parts[0]
            with open(changelog_path) as changelog_file:
                first_line = changelog_file.readline()
                if candidate_release in first_line and "released" in first_line:
                    release = candidate_release
            break
version = release

# -- General configuration ---------------------------------------------------

# If your documentation needs a minimal Sphinx version, state it here.
#
# needs_sphinx = '1.0'

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.todo',
    'sphinx.ext.mathjax',
]

# The suffix(es) of source filenames.
# You can specify multiple suffix as a list of string:
#
# source_suffix = ['.rst', '.md']
source_suffix = '.rst'

# The master toctree document.
master_doc = 'index'

# Additional docs
messages_doc = 'kea-messages'

# The language for content autogenerated by Sphinx. Refer to documentation
# for a list of supported languages.
#
# This is also used if you do content translation via gettext catalogs.
# Usually you set "language" from the command line for these cases.
language = "en"

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = [
    '_build', 'Thumbs.db', '.DS_Store',
    # included files need to be excluded to avoid duplicate labels
    'arm/platforms.rst',
    'arm/hooks-bootp.rst',
    'arm/hooks-class-cmds.rst',
    'arm/hooks-cb-cmds.rst',
    'arm/config-backend.rst',
    'arm/hooks-ha.rst',
    'arm/hooks-host-cache.rst',
    'arm/hooks-lease-cmds.rst',
    'arm/hooks-lease-query.rst',
    'arm/hooks-limits.rst',
    'arm/hooks-radius.rst',
    'arm/hooks-rbac.rst',
    'arm/hooks-run-script.rst',
    'arm/hooks-stat-cmds.rst',
    'arm/hooks-ddns-tuning.rst',
    'arm/hammer.rst',
    'arm/ext-netconf.rst',
    'arm/ext-gss-tsig.rst',
    'grammar/grammar-ca-parser.rst',
    'grammar/grammar-d2-parser.rst',
    'grammar/grammar-dhcp4-parser.rst',
    'grammar/grammar-dhcp6-parser.rst',
    'grammar/grammar-netconf-parser.rst',
    'arm/hooks-flex-id.rst',
    'arm/hooks-flex-option.rst',
    'arm/hooks-legal-log.rst',
    'arm/hooks-gss-tsig.rst',
    'arm/hooks-host-cmds.rst',
    'arm/hooks-cb-mysql.rst',
    'arm/hooks-cb-pgsql.rst',
    'arm/hooks-limits.rst',
    'arm/hooks-rbac.rst',
    'arm/hooks-run-script.rst',
    'arm/hooks-subnet-cmds.rst',
    'arm/hooks-user-chk.rst',
]

# The name of the Pygments (syntax highlighting) style to use.
pygments_style = None


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
#html_theme = 'alabaster'
html_theme = 'sphinx_rtd_theme'
html_logo = 'static/kea-imageonly-100bw.png'

# Theme options are theme-specific and customize the look and feel of a theme
# further.  For a list of options available for each theme, see the
# documentation.
#
#html_theme_options = {
#    "logo": "kea-logo-100x70.png",
#}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['static']

# Custom sidebar templates, must be a dictionary that maps document names
# to template names.
#
# The default sidebars (for documents that don't match any pattern) are
# defined by theme itself.  Builtin themes are using these templates by
# default: ``['localtoc.html', 'relations.html', 'sourcelink.html',
# 'searchbox.html']``.
#
# html_sidebars = {}


# -- Options for HTMLHelp output ---------------------------------------------

# Output file base name for HTML help builder.
#htmlhelp_basename = 'KeaAdministratorReferenceManualdoc'


# -- Options for LaTeX output ------------------------------------------------

latex_elements = {
    # The paper size ('letterpaper' or 'a4paper').
    #
    # 'papersize': 'letterpaper',

    # The font size ('10pt', '11pt' or '12pt').
    #
    # 'pointsize': '10pt',

    # Additional stuff for the LaTeX preamble.
    #
    # 'preamble': '',

    # Latex figure (float) alignment
    #
    # 'figure_align': 'htbp',
}

# Grouping the document tree into LaTeX files. List of tuples
# (source start file, target name, title,
#  author, documentclass [howto, manual, or own class]).
latex_documents = [
    (master_doc, 'kea-arm.tex', 'Kea Administrator Reference Manual Documentation', author, 'manual'),
]

latex_logo = 'static/kea-logo-200.png'

if os.getenv("READTHEDOCS", "False") == "False":
    latex_documents.append((messages_doc, 'kea-messages.tex', 'Kea Messages Manual', author, 'manual'))


# -- Options for manual page output ------------------------------------------

# One entry per manual page. List of tuples
# (source start file, name, description, authors, manual section).
man_pages = [
    (master_doc, 'kea-arm', 'Kea Administrator Reference Manual Documentation', [author], 1),
    ('man/kea-admin.8', 'kea-admin', 'Shell script for managing Kea databases', author, 8),
    ('man/keactrl.8', 'keactrl', 'Shell script for managing Kea', author, 8),
    ('man/kea-ctrl-agent.8', 'kea-ctrl-agent', 'Control Agent process in Kea', author, 8),
    ('man/kea-dhcp4.8', 'kea-dhcp4', 'DHCPv4 server in Kea', author, 8),
    ('man/kea-dhcp6.8', 'kea-dhcp6', 'DHCPv6 server in Kea', author, 8),
    ('man/kea-dhcp-ddns.8', 'kea-dhcp-ddns', 'DHCP-DDNS process in Kea', author, 8),
    ('man/kea-lfc.8', 'kea-lfc', 'Lease File Cleanup process in Kea', author, 8),
    ('man/kea-netconf.8', 'kea-netconf', 'NETCONF agent for configuring Kea', author, 8),
    ('man/kea-shell.8', 'kea-shell', 'Text client for Control Agent process', author, 8),
    ('man/perfdhcp.8', 'perfdhcp', 'DHCP benchmarking tool', author, 8),
]


# -- Extension configuration -------------------------------------------------

# -- Options for todo extension ----------------------------------------------

# If true, `todo` and `todoList` produce output, else they produce nothing.
todo_include_todos = True



# Do generation of api.rst and kea-messages.rst here in conf.py instead of Makefile.am
# so they are available on ReadTheDocs as there makefiles are not used for building docs.
def run_generate_docs(_):
    import os
    import sys
    src_dir = os.path.abspath(os.path.dirname(__file__))
    print(src_dir)
    sys.path.append(src_dir)

    import api2doc
    with open(os.path.join(src_dir, 'api-files.txt')) as af:
        api_files = af.read().split()
    api_files = [os.path.abspath(os.path.join(src_dir, '../..', af)) for af in api_files]
    api2doc.generate(api_files, os.path.join(src_dir, 'api.rst'))

    import mes2doc
    with open(os.path.join(src_dir, 'mes-files.txt')) as mf:
        mes_files = mf.read().split()
    mes_files = [os.path.abspath(os.path.join(src_dir, '../..', mf)) for mf in mes_files]
    mes2doc.generate(mes_files, os.path.join(src_dir, 'kea-messages.rst'))

    # Sphinx has some limitations. It can't import files from outside its directory, which
    # in our case is src/sphinx. On the other hand, we need to have platforms.rst file
    # in top level directory, so it's easily accessible by prospective and first time
    # users. Furthermore, ReadTheDocs does not use the makefile system at all and they rely
    # on sphinx-build only. As a result we need to conduct some Makefile-like operations
    # here. This requires us to copy (or link) the file from the top level to sphinx subdir.
    #
    # The first entry on this list is the actual file to copy, the second is a unique name
    # that will be used when copied over to arm/ directory.
    FILES_TO_COPY = [
        [ '../../platforms.rst', 'platforms.rst' ],
        [ '../examples/template-power-user-home/info.md', 'template-power-user-home.md' ],
        [ '../examples/template-power-user-home/kea-ca-1.conf', 'template-power-user-home-ca-1.conf' ],
        [ '../examples/template-power-user-home/kea-ca-2.conf', 'template-power-user-home-ca-2.conf' ],
        [ '../examples/template-power-user-home/kea-dhcp4-1.conf', 'template-power-user-home-dhcp4-1.conf' ],
        [ '../examples/template-power-user-home/kea-dhcp4-2.conf', 'template-power-user-home-dhcp4-2.conf' ]
    ]

    from shutil import copyfile
    for [a, b] in FILES_TO_COPY:
        src = os.path.join(src_dir, a)
        dst = os.path.join(src_dir, 'arm', b)
        print("Copying %s to %s" % (src, dst))
        copyfile(src, dst)

# custom setup hook
def setup(app):
    if hasattr(app, 'add_css_file'):
        app.add_css_file('kea.css')
    else:
        app.add_stylesheet('kea.css')

    app.connect('builder-inited', run_generate_docs)
