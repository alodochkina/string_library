#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  const char *letter = src;
  char *array = dest;
  if (src != s21_NULL) {
    for (s21_size_t i = 0; i < n; letter++, i++) {
      array[i] = *letter;
    }
//    array[n] = '\0';
  }
  return dest;
}

