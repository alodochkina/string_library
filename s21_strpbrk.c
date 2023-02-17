// Copyright 2022 michaleh

#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  // Analogues to the strpbrk() functions of the standard library
  // The strpbrk() function locates in the null-terminated string str1 the first
  // occurrence of any character in the string str2 and returns a pointer to
  // this character
  s21_size_t i;
  s21_size_t k;
  s21_size_t n = 0;
  char *m = s21_NULL;
  char *s1 = (char *)str1;
  for (i = 0; (s1[i] != '\0') && (n == 0); i++) {
    for (k = 0; str2[k] != '\0'; k++) {
      if (s1[i] == str2[k]) {
        n = i;
        m = &s1[i];
        break;
      }
    }
  }
  return m;
}
