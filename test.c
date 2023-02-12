#include "./s21_string.h"
#include <check.h>
// #include <stdlib.h>
#include <string.h>
// #include <stdio.h>


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

START_TEST(test_s21_strerror_zero) {
    int errnum = 0;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

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

    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");

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
    return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
