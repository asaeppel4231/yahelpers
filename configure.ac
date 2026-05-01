AC_INIT([yahelpers],[0.1],[asaeppel4231@gmx.de])
AM_INIT_AUTOMAKE([foreign subdir-objects no-dependencies])

AC_CONFIG_SRCDIR([assert.h])

# Compiler finden
AC_PROG_CC
AM_PROG_CC_C_O

AC_ARG_ENABLE([tests],
    AS_HELP_STRING([--enable-tests], [Enable test suite]),
    [enable_tests=$enableval],
    [enable_tests=no])
AC_MSG_NOTICE([enable_tests = $enable_tests])

PKG_CHECK_MODULES([CMOCKA], [cmocka])

# Debug → Tests automatisch
if test "x$CFLAGS" = "x-g"; then
    enable_tests=yes
fi

# CI erzwingt Tests
if test "x$CI" = "xtrue"; then
    enable_tests=yes
fi

AM_CONDITIONAL([ENABLE_TESTS], [test "x$enable_tests" = "xyes"])

AC_CONFIG_FILES([
Makefile
yahelpers.pc
tests/Makefile
])
AC_OUTPUT
