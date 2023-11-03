#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *letter = src;
  char *array = dest;
  if (src != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++, letter++) {
      array[i] = *letter;
    }
//    array[n] = '\0';
  }
  return dest;
}