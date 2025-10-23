#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    for (; *str1 == *str2 && *str1 != '\0' && *str2 != '\0'; str1++, str2++) {
      counter++;
    }
  }
  return counter;
}