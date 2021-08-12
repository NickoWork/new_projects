all:Quest_3

Quest_3: main_executable_module.o data_stat.o data_sort.o  data_process.o decision.o data_io.o
	gcc main_executable_module.o data_stat.o data_sort.o  data_process.o decision.o data_io.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_libs/data_sort.c  ../data_module/data_process.c ../yet_another_decision_module/decision.c
	gcc -c main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_libs/data_sort.c ../data_module/data_process.c ../yet_another_decision_module/decision.c 

data_io.o: ../data_libs/data_io.c
	gcc -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	gcc -c ../data_libs/data_stat.c

data_sort.o: ../data_libs/data_sort.c
	gcc -c ../data_libs/data_sort.c

data_process.o: ../data_module/data_process.c ../data_libs/data_stat.h
	gcc -c ../data_module/data_process.c ../data_libs/data_stat.h 

run:
	../../build/./Quest_3

rebuild:
	make clean
	make

clean:
	rm *.o
	rm ../../build/Quest_3