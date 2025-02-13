#include "s21_string.h"

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
 // char str1[1000];
  s21_sprintf(str, "My name is %d", 12);
//  sprintf(str, "My name is %c", '');
  printf("%s\n", str);
  return 0;
}