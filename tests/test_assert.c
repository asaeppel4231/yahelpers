#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <ya-ecosystem/helpers/assert.h>

static void test_assert_no_abort(void** state) {
    (void)state;

    int x = 5;

    ASSERT(x == 5, ASSERT_NO_ABORT);

    assert_true(1);
}

static void test_assert_should_abort(void** state) {
    (void)state;

    expect_assert_failure({
        int x = 4;
        ASSERT(x == 5, ASSERT_FOR_TESTS);
    });
}

int main(void) {
    cmocka_set_message_output(CM_OUTPUT_STDOUT);
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_assert_no_abort),
        cmocka_unit_test(test_assert_should_abort),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
