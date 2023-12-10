#include "./s21_string.h"
#include <check.h>
#include <stdlib.h>
#include <string.h>

START_TEST(test_s21_memchr) {
  const char str[] = "Hello, my darling";
  const char c = 'l';
  s21_size_t n = 5;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(test_s21_memchr_1) {
  const void *str = "Hello, my darling!";
  int c = 'l';
  s21_size_t n = 1;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(test_s21_memchr_2) {
  const void *str = "Hello!";
  int c = 'r';
  s21_size_t n = 6;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(test_s21_memchr_3) {
  const void *str = "Hello!";
  int c = 'r';
  s21_size_t n = 8;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}

START_TEST(test_s21_memcmp) {
  const void *str1 = "Hello, kitty!";
  const void *str2 = "Hello, pitty!";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(test_s21_memcmp_1) {
  const void *str1 = "Hello, pitty!";
  const void *str2 = "Hello, kitty!";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(test_s21_memcmp_2) {
  const void *str1 = "Hello, kitty!";
  const void *str2 = "Hello, kitty!";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}

START_TEST(test_s21_memcpy) {
  char dest[50] = "oh";
  char dest2[50] = "no";
  const char src[50] = "Hello, kitty!";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest2, src, n));
}

START_TEST(test_s21_memmove) {
  const char *src = "Hello, kitty! Hello, kitty!";
  const char *src2 = "Hello, kitty! Hello, kitty!";
  char dest[100] = {0};
  char dest2[100] = {0};
  s21_size_t n = 8;
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest2, src2, n));
}

START_TEST(test_s21_memset) {
  char src[] = "Hello, kitty! Hello, kitty!";
  char src2[] = "Hello, kitty! Hello, kitty!";
  int c = '%';
  s21_size_t n = 10;
  ck_assert_str_eq(s21_memset(src, c, n), memset(src2, c, n));
}

START_TEST(test_s21_strcat) {
  char src[50] = "WTF?";
  char dest[50] = "OMG!";
  char src2[50] = "WTF?";
  char dest2[50] = "OMG!";
  ck_assert_str_eq(s21_strcat(dest, src), strcat(dest2, src2));
}

START_TEST(test_s21_strncat) {
  char src[50] = "WTF?";
  char dest[50] = "OMG!";
  char src2[50] = "WTF?";
  char dest2[50] = "OMG!";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest2, src2, n));
}

START_TEST(test_s21_strncat2) {
  char src[50] = "WTF?";
  char dest[50] = "OMG!";
  char src2[50] = "WTF?";
  char dest2[50] = "OMG!";
  s21_size_t n = 7;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest2, src2, n));
}

START_TEST(test_s21_strchr) {
  const char *str = "I believe I can fly!";
  char c = 'c';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}

START_TEST(test_s21_strchr1) {
  const char *str = "I believe I can fly!";
  char c = 'z';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}

START_TEST(test_s21_strcmp) {
  const void *str1 = "Hello, kitty!";
  const void *str2 = "Hello, pitty!";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(test_s21_strcmp_1) {
  const void *str1 = "Hello, pitty!";
  const void *str2 = "Hello, kitty!";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(test_s21_strcmp_2) {
  const void *str1 = "Hello, kitty!";
  const void *str2 = "Hello, kitty!";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(test_s21_strncmp) {
  const void *str1 = "Hello, kitty!";
  const void *str2 = "Hello, pitty!";
  s21_size_t n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

START_TEST(test_s21_strncmp_1) {
  const void *str1 = "Hello, pitty!";
  const void *str2 = "Hello, kitty!";
  s21_size_t n = 30;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

START_TEST(test_s21_strncmp_2) {
  const void *str1 = "Hello, kitty!";
  const void *str2 = "Hello, kitty!";
  s21_size_t n = 13;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}

START_TEST(test_s21_strcpy) {
  char dest[50] = "oh";
  char dest2[50] = "no";
  const char src[50] = "Hello, kitty!";
  ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest2, src));
}

START_TEST(test_s21_strncpy) {
  char dest[50] = "oh";
  char dest2[50] = "no";
  s21_size_t n = 7;
  const char src[50] = "Hello, kitty!";
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest2, src, n));
}

START_TEST(test_s21_strncpy1) {
  char dest[50] = "oh";
  char dest2[50] = "no";
  s21_size_t n = 30;
  const char src[50] = "Hello, kitty!";
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest2, src, n));
}

START_TEST(test_s21_strcspn) {
  const char *str1 = "askjdnka";
  const char *str2 = "sjhdbf";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg1) {
  const char *str1 = "\n";
  const char *str2 = " \n";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg2) {
  const char *str1 = "\t";
  const char *str2 = " \t";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg3) {
  const char *str1 = " \n";
  const char *str2 = "\n";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg4) {
  const char *str1 = " \t";
  const char *str2 = "\t";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_zero1) {
  const char *str1 = " \0";
  const char *str2 = "\0";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_zero2) {
  const char *str1 = "\0";
  const char *str2 = " \0";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strerror) {
  int errnum = 5;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(test_s21_strrchr) {
  const char *str = "what a fiction!";
  char c = '!';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}

START_TEST(test_s21_strrchr2) {
  const char *str = "what a fiction!";
  char c = 'r';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}

START_TEST(test_s21_strspn) {
  const char *str1 = "Hello, kitty!";
  const char *str2 = "Hello, pitty!";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}

START_TEST(test_s21_strerror_zero) {
  int errnum = -2;
  ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(test_s21_strstr) {
  const char *str = "Hello, Kitty!";
  char *str1 = "Kitty!";
  ck_assert_ptr_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(test_s21_strstr_1) {
  const char *str = "Hello, Kitty!";
  char *str1 = "Pitty!";
  ck_assert_ptr_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(test_s21_strstr_2) {
  const char *str = "Hello, Kitty!";
  char *str1 = "Kitry!";
  ck_assert_ptr_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(test_s21_strpbrk) {
  const char *str1 = "askjdnka";
  const char *str2 = "sjhdbf";
  ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg1) {
  const char *str1 = "\n";
  const char *str2 = " \n";

  ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg2) {
  const char *str1 = "\t";
  const char *str2 = " \t";
  ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg3) {
  const char *str1 = " \n";
  const char *str2 = "\n";
  ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg4) {
  const char *str1 = " \t";
  const char *str2 = "\t";
  ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strlen) {
  const char *str = "test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s;
  TCase *tc_core;
  TCase *tc_limits;
  s = suite_create("s21_string");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strerror);
  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_memcmp_1);
  tcase_add_test(tc_core, test_s21_memcmp_2);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memmove);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_strcat);
  tcase_add_test(tc_core, test_s21_strncat);
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strchr1);
  tcase_add_test(tc_core, test_s21_strcmp);
  tcase_add_test(tc_core, test_s21_strcmp_1);
  tcase_add_test(tc_core, test_s21_strcmp_2);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strncmp_1);
  tcase_add_test(tc_core, test_s21_strncmp_2);
  tcase_add_test(tc_core, test_s21_strcpy);
  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strncpy1);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strrchr2);
  tcase_add_test(tc_core, test_s21_strspn);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strstr_1);
  tcase_add_test(tc_core, test_s21_strstr_2);

  suite_add_tcase(s, tc_core);

  tc_limits = tcase_create("Limits");

  tcase_add_test(tc_core, test_s21_strncat2);
  tcase_add_test(tc_limits, test_s21_strcspn_neg1);
  tcase_add_test(tc_limits, test_s21_strcspn_neg2);
  tcase_add_test(tc_limits, test_s21_strcspn_neg3);
  tcase_add_test(tc_limits, test_s21_strcspn_neg4);
  tcase_add_test(tc_limits, test_s21_strcspn_zero1);
  tcase_add_test(tc_limits, test_s21_strcspn_zero2);
  tcase_add_test(tc_limits, test_s21_strerror_zero);
  tcase_add_test(tc_limits, test_s21_strpbrk_neg1);
  tcase_add_test(tc_limits, test_s21_strpbrk_neg2);
  tcase_add_test(tc_limits, test_s21_strpbrk_neg3);
  tcase_add_test(tc_limits, test_s21_strpbrk_neg4);
  tcase_add_test(tc_core, test_s21_memchr_1);
  tcase_add_test(tc_core, test_s21_memchr_2);
  tcase_add_test(tc_core, test_s21_memchr_3);

  suite_add_tcase(s, tc_limits);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_SILENT);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
