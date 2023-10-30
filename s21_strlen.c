#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  // Analogous to the strlen function of the standard library
  // The strlen function computes the length of the string str.
  s21_size_t i;
  for (i = 0; str[i] != '\0'; i++) {
  }
  return i;
}
