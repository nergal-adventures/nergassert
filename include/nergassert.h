#ifndef NERG_ASSERT

#define NERG_ASSERT

typedef enum ResultCode {
  PASSED,
  FAILED
} test_res_code_e;

typedef struct Result {
 char *str;
 test_res_code_e result;
 char *error_msg;
} test_result_t;


#define assert_equals_str(str_1, str_2, ...) \
  eval_assert_equals_str(str_1, str_2, __func__ __VA_OPT__(,)__VA_ARGS__)

#define assert_not_null(pointer, ...) \
  eval_assert_not_null(pointer, __func__ __VA_OPT__(,)__VA_ARGS__)

test_result_t eval_assert_not_null(void *pointer, const char *func, ...);
test_result_t eval_assert_equals_str(char *str_1, char *str_2, const char *func, ...);
#endif // NERG_ASSERT
