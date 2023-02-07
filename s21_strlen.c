// Copyright 2022 michaleh
#include <stdio.h>
#include "s21_string.h"

// #include <string.h>

// s21_size_t s21_strlen(const char *str);  // Вычисляет длину строки str,
// не включая завершающий нулевой символ.

// int main(void) {
//    const char *str = '\t';
//    printf("%s\"%s\"%s%lu\n%s\"%s\"%s%llu\n",
//           "The length of ", str, " is ", strlen(str));
//          "The length of ", str, " is ", s21_strlen(str));
// }

s21_size_t s21_strlen(const char *str) {
    s21_size_t i;
    for (i = 0; str[i] != '\0'; i++) {}
    return i;
}
