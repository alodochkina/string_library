#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  const char *result = s21_NULL;
  enum result what = not ;
  while (*str) {
    if (*str == (unsigned char)c) {
      what = good;
      result = str;
      break;
    }
    str++;
  }
  if (what == not ) {
    return s21_NULL;
  } else {
    return (char *)result;
  }
}