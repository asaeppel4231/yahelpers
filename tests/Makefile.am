if ENABLE_TESTS
TESTS = test_assert.sh test_log
noinst_PROGRAMS = test_log test_assert

test_log_SOURCES = test_log.c
test_assert_SOURCES = test_assert.c

test_log_LDADD = -lcmocka
test_assert_LDADD = -lcmocka

endif

AM_CPPFLAGS = -I$(includedir)

# test_assert wird über ein Shell-Skript gewrappt
test_assert.sh:
	echo '#!/bin/sh' > test_assert.sh
	echo './test_assert > assert.out 2>&1' >> test_assert.sh
	echo 'echo $$?' >> test_assert.sh
	echo 'exit 0' >> test_assert.sh
	chmod +x test_assert.sh
