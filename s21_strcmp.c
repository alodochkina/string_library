#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  enum result what;
  what = not ;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++) {
      if (*str1 != *str2) {
        if (*str1 > *str2) {
          what = good;
          break;
        } else {
          what = not ;
          break;
        }
      } else {
        if (s21_strlen(str1) == s21_strlen(str2)) {
          what = equal;
        }
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