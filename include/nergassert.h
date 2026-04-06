#ifndef NERG_ASSERT

#define NERG_ASSERT

typedef struct Result test_result_t;

typedef enum ResultCode {
  PASSED,
  FAILED
} test_res_code_e;

typedef struct Result {
 char *str;
 test_res_code_e result;
 char *error_msg;
} test_result_t;


#define assert_not_null(pointer, ...) \
  eval_assert_not_null(pointer __VA_OPT__(,)__VA_ARGS__)

test_result_t eval_assert_not_null(void *pointer, ...);
#endif // NERG_ASSERT
