#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t n = s21_strlen(dest);
  dest[n] = *src;
  return dest;
}