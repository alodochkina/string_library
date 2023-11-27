#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  enum result what;
  const char *catch = s21_NULL;
  what = not ;
  if (str != s21_NULL) {
    for (; *str != '\0'; str++) {
      if (*str == (unsigned char)c) {
        catch = str;
        what = good;
        break;
      }
    }
  }
  if (what == good) {
    return (char *)catch;
  } else
    return s21_NULL;
}