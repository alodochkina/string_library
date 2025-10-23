#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *string = s21_NULL;
  for (; *haystack != '\0'; haystack++) {
    if (*haystack == *needle) {
      string = haystack;
      for (; *needle != '\0'; needle++, haystack++) {
        if (*haystack != *needle) {
          string = s21_NULL;
        }
      }
    }
  }
  return (char *)string;
}