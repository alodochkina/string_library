#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  enum result what = not ;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++, str1++, str2++) {
      if (*str1 != *str2) {
        if (str1 > str2) {
          what = good;
          break;
        } else {
          what = not ;
          break;
        }
      } else {
        what = equal;
      }
    }
  }
  if (what == good) {
    return 5;
  } else if (what == not ) {
    return -5;
  } else {
    return 0;
  }
}