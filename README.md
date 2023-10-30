 Implementation of the <string.h> library in C programming language with implementation of sprintf and sscanf 
functions and four processing string functions from the string class in C#. The string.h library is the main C library 
 for string processing.

# <string.h> 
## Library variables:
- _**size_t**_ - This is the unsigned integral type and is the result of the sizeof keyword

## Library Macros:
- _**NULL**_ - This macro is the value of a null pointer constant

## Library Functions:
- _**void *memchr(const void *str, int c, size_t n)**_ - Searches for the first occurence of the character c (an 
unsigned char) in the first n bytes of the string pointed to, 
by the argument str


- _**int memcmp(const void *str1, const void *str2, size_t n)**_ - Compares the first n bytes of str1 and str2


- _**void *memcpy(void *dest, const void *src, size_t n)**_ - Copies n characters from src to dest


- _**void *memmove(void *dest, const void *src, size_t n)**_ - Another function to copy n characters from str2 to str1


- _**void *memset(void *str, int c, size_t n)**_ - Copies the character c (an unsigned char) to the first n characters 
of the string pointed to, by the argument str


- _**char *strcat(char *dest, const char *src)**_ - Appends the string pointed to, by src to the end of the string 
pointed to by dest

- _**char *strncat(char *dest, const char *src, size_t n)**_ - Appends the string pointed to, by src to the end of the 
string pointed to, by dest up to n characters long


- _**char strchr(const char *str, int c)**_ - Searches for the first occurrence of the character c (an unsigned char) in
the string pointed to, by the argument str


- _**int strcmp(const char *str1, const char *str2)**_ - Compares the string pointed to, by str1 to the string pointed 
to by str2


- _**int strncmp(const char *str1, const char *str2, size_t n)**_ - Compares at most the first n bytes of str1 and str2


- _**char *strcpy(char *dest, const char *src)**_ - Copies the string pointed to, by src to dest


- _**char *strncpy(char *dest, const char *src, size_t n)**_ - Copies up to n characters from the string pointed to, by 
src to dest


- _**size_t strcspn(const char *str1, const char *str2)**_ - Calculates the length of the initial segment of str1 which
consists entirely of characters not in str2


- _**char *strerror(int errnum)**_ - Searches an internal array for the error number errnum and returns a pointer to an 
error message string


- _**size_t strlen(const char *str)**_ - Computes the length of the string str up to but not including the terminating 
null character


- _**char *strpbrk(const char *str, int c)**_ - Finds the first character in the string str1 that matches any character 
specified in str2


- _**char *strrchr(const char *str, int c)**_ - Searches for the last occurence of the character c (an unsigned char) in
the string pointed to by the argument str


- _**size_t strspn(const char *str1, const char *str2)**_ - Calculates the length of the initial segment of the str1 
which consists entirely of characters in str2


- _**char *strstr(const char *haystack, const char *needle)**_ - Finds the first occurrence of the entire string needle
  (not including the terminated null character) which appears in the string haystack


- _**char *strtok(char *str, const char *delim)**_ - breaks string str into a series of tokens separated by delim

# sprintf and sscanf

- _**int sscanf(const char *str, const char *format, ...)**_ - reads formatted input from a string
- _**int sprintf(char *str, const char *format, ...)**_ - sends formatted output to a string pointed to, by str

where:

- _**str**_ - This is the C string that the function processes as its source to retrieve the data
- _**format**_ - This is the C string that contains one or more of the following items: Whitespace character, 
Non-whitespace character and Format specifiers. A format specifiers for print functions follows this prototype: 
%[flags][width][.precision][length]specifier. A format specifier for scan functions follows this prototype: 
%[*][width][length]specifier


# sprintf and sscanf specifiers

- _**c**_ - _sprintf and sscanf output:_ character


- _**d**_ - _sprintf and sscanf output:_ signed decimal integer


- _**i**_ - _sprintf output:_ signed decimal integer; _sscanf output:_ signed integer (may be decimal, octal or 
hexadecimal)


- _**e**_ - _sprintf output:_ scientific nitation (mantissa/exponent) using e character (the output of the numbers must 
match up to e-6); _sscanf output:_ decimal floating point or scientific notation (mantissa/exponent)


- _**E**_ - _sprintf output:_ scientific notation (mantissa/exponent) using E character; _sscanf output:_ decimal 
floating point or scientific notation (mantissa/exponent)


- _**f**_ - _sprintf output:_ decimal floating point; _sscanf output:_ decimal floating point or scientific notation 
(mantissa/exponent)


- _**g**_ - _sprintf output:_ uses the shortest representation of decimal floating point; _sscanf output:_ decimal 
floating point or scientific notation (mantissa/exponent)


- _**G**_ - _sprintf output:_ uses the shortest representation of decimal floating point; _sscanf output:_ decimal 
flaoting point or scientific notation (mantissa/exponent)


- _**o**_ - _sprintf and sscanf output:_ unsigned octal


- _**s**_ - _sprintf and sscanf output:_ string of characters


- _**u**_ - _sprintf and sscanf output:_ unsigned decimal integer


- _**x**_ - _sprintf output:_ unsigned hexadecimal integer; _sscanf output:_ unsigned hexadecimal integer (any letters)


- _**X**_ - _sprintf output:_ unsigned hexadecimal integer (capital letters); _sscanf output:_ unsigned hexadecimal 
integer (any letters)

  
- _**p**_ - _sprintf and sscanf output:_ pointer address


- _**n**_ - _sprintf output:_ number of characters printed until %n occurs; _sscanf output:_ number of characters 
scanned until %n occurs


- _**%**_ - _sprintf and sscanf output:_ character %


# sprintf flags


- _**-**_ - left-justify within the given field width; right justification is the default


- _**+**_ - forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only 
negative numbers are preceded with a -ve sign.


- _**(space)**_ - if no sign is going to be written, a blank space is inserted before the value


- _**#**_ - used with _**o**_, _**x**_ or _**X**_ specifiers the value is preceded with O, Ox or OX respectively
for values different from zero. Used with _**e**_, _**E**_ and _**f**_, it forces the written output to contain a 
decimal point even if no digits follow, no decimal point is written. Used with _**g**_ or _**G**_ the result is the same
as with _**e**_ or _**E**_ but trailing zeros are not removed


- _**0**_ - left-pads the number with zeros (0) instead of spaces, where padding is specified


# sprintf and sscanf width description


- _**(number)**_ - minimum number of characters to be printed. If the value to be printed is shorter than his number, 
the result is padded with blank spaces. The value is not truncated even if the result is larger.


- **_*_** - _**in sprintf**_ the **_*_** sign means, that the width is not specified in the format string, but as an 
additional integer value argument preceding the argument that has to be formatted. _**In sscanf**_ the **_*_** sign 
placed after % and before the format specifier reads data of the specified type, but suppresses their assignment.


# sprintf precision description


- _**.number**_ - for integer specifiers(_**d**_, _**i**_, _**o**_, _**u**_, _**x**_, _**X**_) - precision specifies the
minimum number of digits to be written. If the value to be written is shorter than his number, the result is padded with
leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is
written for the value 0. For _**e**_, _**E**_ and _**f**_ specifiers - this is the number of digits to be printed after 
the decimal point. For _**g**_ and _**G**_ - this is the maximum number of significant digits to be printed. For 
_**s**_ - this is the maximum number of characters to be printed. By default, all characters are printed until the
ending null character is encountered. For _**c**_ type - it has no effect. When no precision is specified for all other 
kind of specifiers, the default is _**1**_. If the period is specified without an explict value for precision, 0 is 
assumed.


- **_.*_** - the precision is not specified in the format string, but as an additional integer value argument preceding 
the argument that has to be formatted.


# sprintf and sscanf length description


- _**h**_ - the argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: 
_**i**_, _**d**_, _**o**_, _**u**_, _**x**_ and _**X**_), and ad a wide character or wide character string for
specifiers _**c**_ and _**s**_.


- _**l**_ - the argument is interpreted as a long int or unsigned long int for integer specifiers (_**i**_, _**d**_,
  _**o**_, _**u**_, _**x**_ and _**X**_), and as a wide character or wide character string for specifiers _**c**_ and
  _**s**_


- _**L**_ - the argument is interpreted as a long double (only applies to floating point specifiers - _**e**_, _**E**_,
  _**f**_, _**g**_, _**G**_)


# special string processing functions (from the string class in C#)


- _**void *to_upper(const char *str)**_ - returns a copy of string (str) converted to uppercase. In case of any error,
return NULL


- _**void *to_lower(const char *str)**_ - returns a copy of a string (str) converted to lowercase. In case of any error, 
return NULL


- _**void *insert(const char *src, const char *str, size_t start_index)**_ - returns a new string in which a specified 
string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, 
return NULL


- _**void trim(const char *src, const char *trim_chars)**_ - returns a new string in which all leading occurrences of a 
set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL
