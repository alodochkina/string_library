// Copyright 2022 michaleh
// #include <stdio.h>
#include "s21_string.h"
// #include <string.h>

// s21_size_t s21_strcspn(const char *str1, const char *str2);

// int main(void) {
//    const char *str1 = "\n";  // указатель на первую строку
//    const char *str2 = " \n";  // указатель на вторую строку
//
//    printf("%s%s\n%s%s\n\n%s\n%s%lu\n%llu\n",
//           "string1 = ", str1, "string2 = ", str2,
//           "The length of the inintial segment of string1",
//           "containing no charachters from string2 = ",
//           strcspn(str1, str2),
//           s21_strcspn(str1, str2));
// }

s21_size_t s21_strcspn(const char *str1, const char *str2) {  // определение длины
    // начального сегмента str1, который полностью состоит из символов не
    // входящих в str2
    s21_size_t i = 0;  // счетчик для первой строки
    s21_size_t k;  // счетчик для второй строки
    s21_size_t n = 2;

    for (i = 0; (str1[i] != '\0') && (n == 2) ; i++) {
        for (k = 0; str2[k] != '\0'; k++) {
            if (str1[i] == str2[k]) {
                n = 1;
                i++;
                break;
            }
        }
    }
    return i;
}
