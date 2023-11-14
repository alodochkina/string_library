#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (src != s21_NULL && dest != s21_NULL) {
    s21_size_t i;
    for (i = 0; *src != '\0' && i < n; i++, src++) {
      dest[i] = *src;
    }
    while (i < n) {
      dest[i] = '\0';
      i++;
    }
  }
  return dest;
}