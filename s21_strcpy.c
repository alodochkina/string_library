#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  if (src != s21_NULL && dest != s21_NULL) {
    s21_size_t i;
    for (i = 0; *src != '\0'; i++, src++) {
      dest[i] = *src;
    }
    dest[i] = '\0';
  }
  return dest;
}