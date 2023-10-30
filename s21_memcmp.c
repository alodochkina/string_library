#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  enum result what;
  const unsigned int *string1 = s21_NULL;
  const unsigned int *string2 = s21_NULL;
  what = not;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    s21_size_t k = s21_strlen(str1);
    s21_size_t m = s21_strlen(str2);
    for (s21_size_t i = 0; i < n && i < k && i < m; i++, str1++, str2++) {
       string1 = str1;
       string2 = str2;
      if (*string1 != *string2) {
        if (*string1 > *string2) {
          what = good;
          break;
        } else {
          what = not;
          break;
        }
      } else {
        if ( k == m) {
          what = equal;
        }
      }
    }
  } if (what == good) {
    return 5;
  } else
  if (what == not) {
    return -5;
  } else {
    return 0;
  }
}