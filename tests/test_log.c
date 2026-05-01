#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <ya-ecosystem/helpers/log.h>

static void test_log_debug(void** state) {
    (void)state;

    LOG_DEBUG("Hello from test\n");
    LOG_DEBUG("Value: %d\n", 42);

    assert_true(1);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_log_debug),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
