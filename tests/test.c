#include "nergassert.h"
#include <stdio.h>
#include <stdlib.h>


void test_assert_not_null_positive() {
  printf("Test - %s - Started\n", __func__);
  void *ptr = malloc(sizeof(void *));
  test_result_t result = assert_not_null(ptr);
  

  if (result.error_msg == NULL) {
    printf("Test - %s - %s\n", __func__, result.str);
  }
  printf("Test - %s - Finshed\n", __func__);
}

void test_assert_not_null_negative() {
  printf("Test - %s - Started\n", __func__);
  void *ptr = NULL;
  test_result_t result = assert_not_null(ptr);
  printf("Test - %s - Finshed\n", __func__);
  printf("Test - %s - %s\n", __func__, result.str);
}

void test_assert_not_null_with_message_negative() {
  printf("Test - %s - Started\n", __func__);
  void *ptr = NULL;
  test_result_t result = assert_not_null(ptr, "Ptr must not be null.");
  printf("Test - %s - Finshed\n", __func__);
  printf("Test - %s - %s\n", __func__, result.str);
}

int main() {
  test_assert_not_null_positive();
  test_assert_not_null_negative();
  test_assert_not_null_with_message_negative();
}
