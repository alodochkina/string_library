#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>

#define s21_size_t unsigned long long
#define s21_NULL (void *)0


s21_size_t s21_strcspn(const char *str1, const char *str2);
// Analogues to the strcspn function of the standard library.
// The strcspn() function spans the initial part of the null-terminated string
// str1  as long as the characters from str1 do not occur in the null-terminated
// string str2.

char *s21_strerror(int errnum);
// Analogues to the strerror function of the standard library.
// The strerror() function accepts an error number argument errnum and returns
// a pointer to the corresponding message string.

s21_size_t s21_strlen(const char *str);
// Analogues to the strlen function of the standard library.
// The strlen() function computes the length of the string str.

char *s21_strpbrk(const char *str1, const char *str2);
// Analogues to the strpbrk function of the standard library.
// The strpbrk() function locates in the null-terminated string str1 the first
// occurrence of any character in the string str2 and returns a pointer to this
// character.

#endif //  SRC_S21_STRING_H_