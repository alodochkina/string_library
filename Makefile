FLAGS = -Wall -Werror -Wextra -std=c11
OBJECTS_C = s21_strcspn.c s21_strerror.c s21_strlen.c s21_strpbrk.c
OBJECTS_O = s21_strcspn.o s21_strerror.o s21_strlen.o s21_strpbrk.o
all: s21_string.a gcov_report
rebuild: gcov_report test
s21_string.o:
	gcc $(FLAGS) -c $(OBJECTS_C)
clean:
	rm -rf *.o test out *.info *.gcda *.gcno *.gcov *.gch *.out *.a
test: s21_string.o
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(OBJECTS_C) -o test test.c -lcheck -lm -lpthread
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