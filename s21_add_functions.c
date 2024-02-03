#include "s21_string.h"

void check_format(const char *format) {
 // ptrS21_forma new_forma;
  ptrS21_forma curr_forma;
  int count = 0, i = 0;
  while (*format != '\0' && count < 5){
    ptrS21_forma new_forma = malloc(sizeof(S21_forma));
    if (new_forma != s21_NULL) {
      i = 0;
      if (*format == '%') {
        new_forma->str_format[i] = *format;
        format++;
        i++;
      }
      for (; *format != '%' && *format != '\0'; format++, i++) {
        new_forma->str_format[i] = *format;
      }
      new_forma->next_format = curr_forma;
      curr_forma = new_forma;
    } count++;
    free(new_forma);
  } curr_forma->next_format = s21_NULL;

}