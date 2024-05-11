all: gcov_report

clean:
	rm -rf check *.o *.a *.gcno *.html *.gcda
	rm -rf ./report/
	rm -rf report.info

clang_test:
	clang-format -n -style=Google src/*.c src/*.h

check:
	gcc -Wall -Wextra -Werror -o check src/quadratic_equation.c src/tests.c --coverage -lcheck -lm -lpthread -lsubunit 
	 ./check

gcov_report: clean check
	gcov -o report.info -c -d .
	lcov -t "check" -o report.info -c -q -d .
	genhtml -o report report.info
	open ./report/index.html
