#include "s21_string.h"
#include <string.h>

int s21_sprintf(char *str, const char* format, ...) {
  S21_forma* first_point = malloc(sizeof(S21_forma));
  S21_forma* curr_point = first_point;
  check_format(format, curr_point);
  parser_format(curr_point);
  va_list arg;
  va_start(arg, format);
  while(curr_point) {
    switch (curr_point->parser.specifier) {
    case no_specifier:
      if(curr_point->str_format[strlen(curr_point->str_format) - 1] == '%') {
        curr_point->str_format[strlen(curr_point->str_format) - 1] = '\0';
      }
      curr_point->str_argument = curr_point->str_format;
      curr_point->str_format = "";
      break;
    case c:
    case percent:
    case p:
    case n:
    case s:
      curr_point->str_argument = va_arg(arg, char*);
      break;
    case d:
    case i:
    case o:
    case u:
    case x:
    case X:
      curr_point->str_argument = va_arg(arg, long*);
      break;
    case e:
    case E:
    case f:
    case g:
    case G:
      curr_point->str_argument = va_arg(arg, double *);
      break;
    } curr_point = curr_point->next_format;
  }
  va_end(arg);
  print(str,first_point);
  return 0;
}

int main() {
  char str[1000];
  char str1[1000];
  s21_sprintf(str, "My name is %", "eee");
  puts("pupu");
  sprintf(str1, "My name is %", "eee");
  printf("%s\n%s\n", str, str1);
  return 0;
}