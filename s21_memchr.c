#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  enum result what;
  what = not;
  const unsigned char *letter = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t k = s21_strlen(str);
    for (s21_size_t i = 0; i < n && i < k; str++, i++) {
      letter = str;
      if ((unsigned char)c == *letter) {
        what = good;
        break;
      }
    }
  } if (what == not) {
    return 0;
  } else {
    return (void *)letter;
  }
}