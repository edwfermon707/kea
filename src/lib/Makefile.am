# The following build order must be maintained.
SUBDIRS = exceptions util log cryptolink dns asiolink cc

if HAVE_GTEST
SUBDIRS += testutils
endif

SUBDIRS += database

if HAVE_MYSQL
SUBDIRS += mysql
endif

if HAVE_PGSQL
SUBDIRS += pgsql
endif

SUBDIRS += config_backend hooks dhcp tcp http config stats

if HAVE_NETCONF
SUBDIRS += yang
endif

SUBDIRS += asiodns dhcp_ddns eval process dhcpsrv d2srv
