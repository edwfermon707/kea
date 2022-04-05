SUBDIRS = .

AM_CPPFLAGS = -I$(top_builddir)/src/lib -I$(top_srcdir)/src/lib
AM_CPPFLAGS += -I$(top_builddir)/src/hooks/agent/rbac -I$(top_srcdir)/src/hooks/agent/rbac
AM_CPPFLAGS += $(BOOST_INCLUDES)
AM_CPPFLAGS += -DRBAC_LIB_SO=\"$(abs_top_builddir)/src/hooks/agent/rbac/.libs/libdhcp_rbac.so\"
AM_CPPFLAGS += -DINSTALL_PROG=\"$(abs_top_srcdir)/install-sh\"
AM_CPPFLAGS += -DAPI_DIR=\"$(abs_top_srcdir)/src/share/api\"

AM_CXXFLAGS = $(KEA_CXXFLAGS)

if USE_STATIC_LINK
AM_LDFLAGS = -static
endif

# Unit test data files need to get installed.
EXTRA_DIST =

CLEANFILES = *.gcno *.gcda

# TESTS_ENVIRONMENT = $(LIBTOOL) --mode=execute $(VALGRIND_COMMAND)
LOG_COMPILER = $(LIBTOOL)
AM_LOG_FLAGS = --mode=execute

TESTS =
if HAVE_GTEST
TESTS += rbac_unittests

rbac_unittests_SOURCES = run_unittests.cc
rbac_unittests_SOURCES += rbac_unittests.cc
rbac_unittests_SOURCES += rbac_acl_unittests.cc
rbac_unittests_SOURCES += rbac_api_unittests.cc
rbac_unittests_SOURCES += rbac_callout_unittests.cc
rbac_unittests_SOURCES += rbac_config_unittests.cc
rbac_unittests_SOURCES += rbac_role_unittests.cc

rbac_unittests_CPPFLAGS = $(AM_CPPFLAGS) $(GTEST_INCLUDES) $(LOG4CPLUS_INCLUDES)

rbac_unittests_LDFLAGS  = $(AM_LDFLAGS) $(CRYPTO_LDFLAGS) $(GTEST_LDFLAGS)

rbac_unittests_CXXFLAGS = $(AM_CXXFLAGS)

rbac_unittests_LDADD  = $(top_builddir)/src/hooks/agent/rbac/librbac.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/process/libkea-process.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/http/libkea-http.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/dhcp/libkea-dhcp++.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/hooks/libkea-hooks.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/database/libkea-database.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/cc/libkea-cc.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/dns/libkea-dns++.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/cryptolink/libkea-cryptolink.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/log/libkea-log.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/util/libkea-util.la
rbac_unittests_LDADD += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
rbac_unittests_LDADD += $(LOG4CPLUS_LIBS)
rbac_unittests_LDADD += $(CRYPTO_LIBS)
rbac_unittests_LDADD += $(BOOST_LIBS)
rbac_unittests_LDADD += $(GTEST_LDADD)
endif
noinst_PROGRAMS = $(TESTS)
