#include "nergassert.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_RESET_ALL    "\x1b[0m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RED    "\x1b[31m"

#define STR_PASSED        ANSI_COLOR_GREEN "\xE2\x9C\x94 PASSED" ANSI_RESET_ALL
#define STR_FAILED        ANSI_COLOR_RED "\xE2\x9C\x98 FAILED" ANSI_RESET_ALL

test_result_t eval_assert_equals_str(
    char *str_1, 
    char *str_2, 
    const char *func, 
    ...
    )
{
  va_list args;
  va_start(args, func);
  char *message = va_arg(args, char *);
  va_end(args);

  test_result_t *res = malloc(sizeof(test_result_t));
  if (strlen(str_1) != strlen(str_2)) {
      res->str = STR_FAILED;
      res->result = FAILED;
      printf("[%s]:\t%s\t '%s' not equals to '%s'\t%s\n", 
          func, STR_FAILED, str_1, str_2, message);
      return *res;
  }
  while (*str_1 != '\0' && *str_2 != '\0') {
    if (*str_1 != *str_2) {
      res->str = STR_FAILED;
      res->result = FAILED;
      printf("[%s]:\t%s\t%s\n", func, STR_FAILED, message);
      return *res;
      break;
    }
    str_1 ++;
    str_2 ++;
  }
  res->str = STR_PASSED;
  res->result = PASSED;
  printf("[%s]:\t%s\n", func, STR_PASSED);

  return *res;
}

test_result_t eval_assert_not_null(void *ptr, const char *func, ...)
{
  //Capture the message argument
  va_list args;
  va_start(args, func);
  char *message = va_arg(args, char *);
  va_end(args);

  test_result_t *res = malloc(sizeof(test_result_t));
  if (ptr != NULL) {
    res->str = STR_PASSED;
    res->result = PASSED;
    printf("[%s]:\t%s\n", func, STR_PASSED);
  } else {
    res->str = STR_FAILED;
    res->result = FAILED;
    printf("[%s]:\t%s\t%s\n", func, STR_FAILED, message);
//    assert(ptr);
  }
  return *res;
}
