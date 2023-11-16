#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i;
  s21_size_t k;
  s21_size_t n = 2;

  for (i = 0; (str1[i] != '\0') && (n == 2); i++) {
    for (k = 0; str2[k] != '\0'; k++) {
      if (str1[i] == str2[k]) {
        n = 1;
        i--;
        break;
      }
    }
  }
  return i;
}
