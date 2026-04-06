#include "nergassert.h"
#include <assert.h>
#include <stdlib.h>

#define ANSI_RESET_ALL    "\x1b[0m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RED    "\x1b[31m"

#define STR_PASSED        ANSI_COLOR_GREEN "\xE2\x9C\x94 PASSED" ANSI_RESET_ALL
#define STR_FAILED        ANSI_COLOR_RED "\xE2\x9C\x98 FAILED" ANSI_RESET_ALL

test_result_t eval_assert_not_null(void *ptr, ...)
{
  test_result_t *res = malloc(sizeof(test_result_t));
  if (ptr != NULL) {
    res->str = STR_PASSED;
    res->result = PASSED;
  } else {
    res->str = STR_FAILED;
    res->result = FAILED;
    assert(ptr);
  }
  return *res;
}
