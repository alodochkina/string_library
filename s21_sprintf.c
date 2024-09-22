#include "s21_string.h"

int s21_sprintf(char *str, const char* format, ...) {
  S21_forma start_point;
  S21_forma* curr_point = &start_point;
  check_format(format, curr_point);
  va_list arg;
  char* string = (char*)malloc(sizeof(char) * 1000);
  if (string != s21_NULL) {
    va_start(arg, format);
    while ((string = va_arg(arg, char *)) != s21_NULL) {
      if (*curr_point->str_format == '%' ) {
        curr_point->str_argument = string;
        curr_point = curr_point->next_format;
      } else {
        curr_point->str_argument = curr_point->str_format;
        curr_point->str_format = "";
        curr_point = curr_point->next_format;
        curr_point->str_argument = string;
      }
    }
  } va_end(arg);
  parser_format(&start_point);
  print(str,&start_point);
  free(string);
  return 0;
}

int main() {
  char str[1000];
 // char str1[1000];
  s21_sprintf(str, "My name is %%", 'w');
//  sprintf(str, "My name is %%", 'lklk');
  printf("%s\n", str);
  return 0;
}