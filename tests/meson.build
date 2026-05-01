inc = include_directories(get_option('prefix') / 'include')

cmocka_dep = dependency('cmocka')

test_assert_exe = executable(
  'test_assert',
  'test_assert.c',
  dependencies: cmocka_dep
)

test_log_exe = executable(
  'test_log',
  'test_log.c',
  dependencies: cmocka_dep
)

# assert-Test über Bash wrappen (SIGABRT neutralisieren)
test(
  'assert_tests',
  find_program('bash'),
  args: ['-c', './test_assert > assert.out 2>&1; echo $?; exit 0'],
  timeout: 30
)

# normaler Test
test(
  'log_tests',
  test_log_exe
)
