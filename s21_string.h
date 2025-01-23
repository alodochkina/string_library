#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)
typedef unsigned long s21_size_t;

enum flags { no_flag,  minus, plus, space, number_sign, null };
enum widths { no_width, number, asteriks };
enum precisions { no_precision, point_number, point_asteriks };
enum lengths { no_length, h, l, L };
enum specifiers { no_specifier, c, d, i, e, E, f, g, G, o, s, u, x, X, p, n,
                  percent};
enum signs { positive, negative };

struct s21_parse_format {
  enum flags flag;
  enum widths width;
  int width_num;
  enum precisions precision;
  int precision_num;
  enum lengths length;
  enum specifiers specifier;
};

typedef struct s21_parse_format S21_parse_format;

struct s21_forma {
  char* str_format;
  void* str_argument;
  char* result_string;
  S21_parse_format parser;
  struct s21_forma* next_format;
};

typedef struct s21_forma S21_forma;

enum result { not, equal, good };


void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char* format, ...);
void check_format(const char* format, S21_forma* curr_point);
void parser_format(S21_forma* curr_point);
void check_flags(S21_forma* curr_point, int* i);
void check_width(S21_forma* curr_point, int* i);
void check_precision(S21_forma* curr_point, int* i);
void check_length(S21_forma* curr_point, int* i);
void check_specifier(S21_forma* specifier, int* i);
int char_to_int(char c);
char* int_to_string(long d);
char* uint_to_string(long d);
char* oct_to_string(long d);
char* hex_to_string(long d, int up);
char* float_to_string(char* d);
void print(char* str, S21_forma* start_point);
void print_character(S21_forma* curr_point, char* res);
void print_integer(S21_forma* curr_point, char* res);
void print_float(S21_forma* curr_point, char* res);
char* print_others(S21_forma* curr_point);
#endif //  SRC_S21_STRING_H_