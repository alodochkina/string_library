#include "s21_string.h"

int s21_sprintf(char *str, const char* format, ...) {
  check_format(format);
  va_list arg;
  char **string = (char **)malloc(sizeof(char*) * 1000 * 1000);
  if (string != s21_NULL) {
    va_start(arg, format);
    while ((*string = va_arg(arg, char *)) != s21_NULL) {
      //  printf("%s\n", *string);
    }
  }

//  s21_print(str);
  va_end(arg);
  free(string);
  return 0;
  //return (int)s21_strlen(str);
}

int main() {
  char str[1000];
 s21_sprintf(str, "My name is %sddd", "ko", "cc");
//  sprintf(str, "%f.4%d.5", 0.65, 65);
//  printf("%s\n", str);
  return 0;
}