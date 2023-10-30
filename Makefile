FLAGS = -Wall -Werror -Wextra -std=c11
LDFLAGS=-L/opt/homebrew/lib
IFLAGS=-I/opt/homebrew/include
OBJECTS_C = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strcat.c s21_strchr.c s21_strcmp.c \
	s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c s21_strpbrk.c \
	s21_strrchr.c s21_strspn.c s21_strstr.c s21_strtok.c
OBJECTS_O = s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memmove.o s21_memset.o s21_strcat.o s21_strchr.o s21_strcmp.o \
	s21_strcpy.o s21_strcspn.o s21_strerror.o s21_strlen.o s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o \
	s21_strrchr.o s21_strspn.o s21_strstr.o s21_strtok.o \
all: s21_string.a gcov_report
rebuild: clean gcov_report test
s21_string.o:
	gcc $(FLAGS) -c $(OBJECTS_C)
clean:
	rm -rf *.o test out *.info *.gcda *.gcno *.gcov *.gch *.out *.a
test: s21_string.o
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(IFLAGS)  $(OBJECTS_C) -o test test.c $(LDFLAGS)  -lcheck -lm -lpthread
	./test
s21_string.a: s21_string.o
	ar rc s21_string.a $(OBJECTS_O)
	ranlib s21_string.a
gcov_report: s21_string.o test
	gcov test.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
style:
	clang-format -n $(OBJECTS_C) s21_string.h