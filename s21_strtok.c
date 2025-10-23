#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  char *result = str;
  enum result what = not ;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == *delim) {
      what = good;
      result[i] = '\0';
      break;
    }
  }
  if (what == good) {
    return result;
  } else if (s21_strlen(result) == s21_strlen(str)) {
    return result;
  } else {
    return s21_NULL;
  }
}