CC = gcc -std=c11
FLAGS = -Wall -Wextra -Werror
LIBS = --coverage -lcheck -lm -lpthread -lsubunit 
NAME = quadratic_equation

all: check

clean:
	rm -rf ${NAME} *.o *.a *.gcno *.html *.gcda
	rm -rf ./report/
	rm -rf report.info

clang_test:
	clang-format -n -style=Google *.c *.h

check:
	${CC} ${FLAGS} -o ${NAME} ${NAME}.c tests.c ${LIBS}
	 ./${NAME}

gcov_report: clean check
	gcov -o report.info -c -d .
	lcov -t "${NAME}" -o report.info -c -q -d .
	genhtml -o report report.info
	open ./report/index.html
