SUBDIRS = .

AM_CPPFLAGS = -I$(top_builddir)/src/lib -I$(top_srcdir)/src/lib
AM_CPPFLAGS += -I$(top_builddir)/src/hooks/dhcp/pre_process -I$(top_srcdir)/src/hooks/dhcp/pre_process
AM_CPPFLAGS += $(BOOST_INCLUDES)
AM_CPPFLAGS += -DPRE_PROCESS_LIB_SO=\"$(abs_top_builddir)/src/hooks/dhcp/pre_process/.libs/libdhcp_pre_process.so\"
AM_CPPFLAGS += -DINSTALL_PROG=\"$(abs_top_srcdir)/install-sh\"

AM_CXXFLAGS = $(KEA_CXXFLAGS)

if USE_STATIC_LINK
AM_LDFLAGS = -static
endif

# Unit test data files need to get installed.
EXTRA_DIST =

CLEANFILES = *.gcno *.gcda

TESTS_ENVIRONMENT = $(LIBTOOL) --mode=execute $(VALGRIND_COMMAND)

LOG_COMPILER = $(LIBTOOL)
AM_LOG_FLAGS = --mode=execute

TESTS =
if HAVE_GTEST
TESTS += pre_process_unittests

pre_process_unittests_SOURCES = run_unittests.cc
pre_process_unittests_SOURCES += callout_unittests.cc
pre_process_unittests_SOURCES += load_unload_unittests.cc

pre_process_unittests_CPPFLAGS = $(AM_CPPFLAGS) $(GTEST_INCLUDES) $(LOG4CPLUS_INCLUDES)

pre_process_unittests_LDFLAGS  = $(AM_LDFLAGS) $(CRYPTO_LDFLAGS) $(GTEST_LDFLAGS)

pre_process_unittests_CXXFLAGS = $(AM_CXXFLAGS)

pre_process_unittests_LDADD  = $(top_builddir)/src/lib/dhcpsrv/libkea-dhcpsrv.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/process/libkea-process.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/eval/libkea-eval.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/dhcp_ddns/libkea-dhcp_ddns.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/stats/libkea-stats.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/config/libkea-cfgclient.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/http/libkea-http.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/dhcp/libkea-dhcp++.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/hooks/libkea-hooks.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/database/libkea-database.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/cc/libkea-cc.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/dns/libkea-dns++.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/cryptolink/libkea-cryptolink.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/log/libkea-log.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/util/libkea-util.la
pre_process_unittests_LDADD += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
pre_process_unittests_LDADD += $(LOG4CPLUS_LIBS)
pre_process_unittests_LDADD += $(CRYPTO_LIBS)
pre_process_unittests_LDADD += $(BOOST_LIBS)
pre_process_unittests_LDADD += $(GTEST_LDADD)
endif
noinst_PROGRAMS = $(TESTS)
