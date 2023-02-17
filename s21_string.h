#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
//
//#include <float.h>
//#include <math.h>
//#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
//#include <limits.h> // Для max и min значений типов

#define s21_size_t unsigned long long
#define s21_NULL (void *)0


s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);


#endif //  SRC_S21_STRING_H_