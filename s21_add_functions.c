#include "s21_string.h"
#include <string.h>

void check_format(const char *format, S21_forma* curr_point) {
  int size = strlen(format) + 1;
  char* string = (char*)malloc(sizeof(char)*size);
  char* str;
  strcpy(string, format);
  S21_forma* new_point;
  for (int i = 0; *format != '\0'; i++, format++) {
    if (*format == '%' && i != 0) {
      str = malloc(sizeof(char)*i);
      strncpy(str, string, i);
      string += i;
      curr_point->str_format = str;
      i = 0;
      new_point = malloc(sizeof(S21_forma));
      curr_point->next_format = new_point;
      curr_point = new_point;
    }
  } if (*string != '\0') {
    curr_point->str_format = string;
  }
}

void parser_format(S21_forma* curr_point) {
  int i = 1;
  while (curr_point != s21_NULL) {
    if (*curr_point->str_format == '%') {
      check_flags(curr_point, &i);
      check_width(curr_point, &i);
      check_precision(curr_point, &i);
      check_length(curr_point, &i);
      check_specifier(curr_point, &i);
    }
    curr_point = curr_point->next_format;
    i = 1;
  }
}

void check_flags(S21_forma* curr_point, int* i) {
  switch (curr_point->str_format[*i]) {
  case '-': curr_point->parser.flag = minus; ++*i; break;
  case '+': curr_point->parser.flag = plus; ++*i; break;
  case ' ': curr_point->parser.flag = space; ++*i; break;
  case '#': curr_point->parser.flag = number_sign; ++*i; break;
  case '0': curr_point->parser.flag = null; ++*i; break;
  default: curr_point->parser.flag = no_flag;
  }
}

void check_width(S21_forma* curr_point, int* i) {
  if ((int)curr_point->str_format[*i] > 47 && (int)curr_point->str_format[*i] < 58) {
    curr_point->parser.width = number;
    int num = char_to_int(curr_point->str_format[(*i)++]);
    while((int)curr_point->str_format[*i] > 47 && (int)curr_point->str_format[*i] < 58 ) {
      num *= 10;
      num += char_to_int(curr_point->str_format[(*i)++]);
    }
    curr_point->parser.width_num = num;
  } else if (curr_point->str_format[*i] == '*') {
    curr_point->parser.width = asteriks;
    ++*i;
  } else {
    curr_point->parser.width = no_width;
  }
}

void check_precision(S21_forma* curr_point, int* i) {
  if (curr_point->str_format[*i] == '.') {
    ++*i;
    curr_point->parser.precision = point_number;
    if (curr_point->str_format[*i] == '*') {
      curr_point->parser.precision = point_asteriks;
    } else if ((int)curr_point->str_format[*i] > 47 && (int)curr_point->str_format[*i] < 58){
      int num = char_to_int(curr_point->str_format[(*i)++]);
      while ((int)curr_point->str_format[*i] > 47 &&
             (int)curr_point->str_format[*i] < 58) {
        num *= 10;
        num += char_to_int(curr_point->str_format[(*i)++]);
      } curr_point->parser.precision_num = num;
    }
  } else {
    curr_point->parser.precision = no_precision;
  }
}

void check_length(S21_forma* curr_point, int* i) {
  switch (curr_point->str_format[*i]) {
  case 'h': curr_point->parser.length = h; ++*i; break;
  case 'l': curr_point->parser.length = l; ++*i; break;
  case 'L': curr_point->parser.length = L; ++*i; break;
  default: curr_point->parser.length = no_length;
  }
}

void check_specifier(S21_forma* curr_point, int* count) {
  switch (curr_point->str_format[*count]) {
  case 'c': curr_point->parser.specifier = c; ++*count; break;
  case 'd': curr_point->parser.specifier = d; ++*count; break;
  case 'i': curr_point->parser.specifier = i; ++*count; break;
  case 'e': curr_point->parser.specifier = e; ++*count; break;
  case 'E': curr_point->parser.specifier = E; ++*count; break;
  case 'f': curr_point->parser.specifier = f; ++*count; break;
  case 'g': curr_point->parser.specifier = g; ++*count; break;
  case 'G': curr_point->parser.specifier = G; ++*count; break;
  case 'o': curr_point->parser.specifier = o; ++*count; break;
  case 's': curr_point->parser.specifier = s; ++*count; break;
  case 'u': curr_point->parser.specifier = u; ++*count; break;
  case 'x': curr_point->parser.specifier = x; ++*count; break;
  case 'X': curr_point->parser.specifier = X; ++*count; break;
  case 'p': curr_point->parser.specifier = p; ++*count; break;
  case 'n': curr_point->parser.specifier = n; ++*count; break;
  case '%': puts("ololo");curr_point->parser.specifier = percent; puts("%");++*count; break;
  default: curr_point->parser.specifier = no_specifier;
  }
}

int char_to_int(char c) {
  int res;
  switch(c){
  case 48: res = 0; break;
  case 49: res = 1; break;
  case 50: res = 2; break;
  case 51: res = 3; break;
  case 52: res = 4; break;
  case 53: res = 5; break;
  case 54: res = 6; break;
  case 55: res = 7; break;
  case 56: res = 8; break;
  case 57: res = 9; break;
  } return res;
}

char* int_to_string(long long d) {
  int minus = 1;
  if (d < 0) {
    minus = 0;
    d *= -1;
  }
  long num = d;
  long sum = d;
  int count = 0;
  int* result_number = malloc((count+1)*sizeof(int));
  while(num >= 1) {
    num/= 10;
    count++;
    result_number[count-1] = sum - num * 10;
    sum = num;
    result_number = realloc(result_number,(count + 1) * sizeof(int));
  }
  if (minus == 0) {
    count++;
    result_number = realloc(result_number, (count + 1) * sizeof(int));
    result_number[count - 1] = 45;
  }
  char* result_char = malloc((count+1)*sizeof(char));
  for(int i = 0, j = count - 1; i < count; i++, j--) {
    switch(result_number[i]) {
    case 0: result_char[j] = '0'; break;
    case 1: result_char[j] = '1'; break;
    case 2: result_char[j] = '2'; break;
    case 3: result_char[j] = '3'; break;
    case 4: result_char[j] = '4'; break;
    case 5: result_char[j] = '5'; break;
    case 6: result_char[j] = '6'; break;
    case 7: result_char[j] = '7'; break;
    case 8: result_char[j] = '8'; break;
    case 9: result_char[j] = '9'; break;
    case 45: result_char[j] = '-'; break;
    default:;
    }
  }
  return result_char;
}

char* oct_to_string(long long d) {
  if (d < 0) {
    d = UINT32_MAX + d + 1;
  }
  double num = (unsigned long)d;
  unsigned long sum = (unsigned long)d / 8;
  int count = 0;
  long result_number = 0;
  if ((unsigned long)d <= 8) {
    return int_to_string(d);
  } else {
    do {
      num = (num / 8 - sum) * 8;
      count++;
      for (int i = 0; i < count - 1; i++) {
        num *= 10;
      }
      result_number += num;
      num = sum;
      sum /= 8;

    } while (num >= 1);
    printf("%ld ", result_number);
    puts("result_number");
  } return int_to_string(result_number);
}

void print(char* string, S21_forma* curr_point) {
  char res[1000];
  while (curr_point != s21_NULL) {
    if (curr_point->parser.specifier == no_specifier ||
        curr_point->parser.specifier == c ||
        curr_point->parser.specifier == s ||
        curr_point->parser.specifier == percent) {
      print_character(curr_point, res);
    } else if (curr_point->parser.specifier == d ||
               curr_point->parser.specifier == i ||
               curr_point->parser.specifier == o ||
               curr_point->parser.specifier == u ||
               curr_point->parser.specifier == x ||
               curr_point->parser.specifier == X) {
      print_integer(curr_point, res);
    } else if (curr_point->parser.specifier == e ||
               curr_point->parser.specifier == E ||
               curr_point->parser.specifier == f ||
               curr_point->parser.specifier == g ||
               curr_point->parser.specifier == G) {
        curr_point->result_string = print_float(curr_point);
      } else if (curr_point->parser.specifier == p ||
               curr_point->parser.specifier == n) {
        curr_point->result_string = print_others(curr_point);
    } curr_point = curr_point->next_format;
    printf("%s\n", res);
    puts("lop");
  }
}

void print_character(S21_forma* curr_point, char* res) {
  if (curr_point->parser.specifier == c) {
    char *c = curr_point->str_argument;
    int size = strlen(res);
    *(res+size) = (long)curr_point->str_argument - 0;
  } else {
    strcat(res, curr_point->str_argument);
  }
}

void print_integer(S21_forma* curr_point, char* res) {
  char *s = malloc(sizeof(curr_point->str_argument));
  if (curr_point->parser.specifier == d || curr_point->parser.specifier == i ||
      (curr_point->parser.specifier == u && (long)curr_point->str_argument >= 0))
    s = int_to_string((long)curr_point->str_argument);
  if (curr_point->parser.specifier == u && (long)curr_point->str_argument < 0)
    s = int_to_string(UINT32_MAX + (long)curr_point->str_argument + 1);
  if (curr_point->parser.specifier == o)
    s = oct_to_string((long)curr_point->str_argument);
    strcat(res, s);
}

char* print_float(S21_forma* curr_point) {
  char* str = " ";
  return str;
}

char* print_others(S21_forma* curr_point) {
  char* str = " ";
  return str;
}