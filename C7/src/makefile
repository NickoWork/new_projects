all:Quest_1

Quest_1: s21_string.c s21_string_test.c
	gcc -Wall -Werror -Wextra s21_string.c s21_string_test.c -o ../build/Quest_1

run:
	../build/./Quest_1

clean:
	rm ../build/Quest_1

rebuild:
	make clean
	make
check:
	python ../materials/linters/cpplint.py s21_string.c
	python ../materials/linters/cpplint.py s21_string_test.c
