#include <stdio.h>

#define LEN 10
void cl (int *buff1, int *buff2);
int input(int *buff1, int *buff2, int *len1, int *len2);
void output(int *buff1, int len1, int *buff2, int len2, int *result, int result_length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int i;

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int buff1[LEN], buff2[LEN], test, len1 = 0, len2 = 0;
	int result[LEN], result_length = 0;
    cl(buff1, buff2);
    test = input(buff1, buff2, &len1, &len2);
    //printf("len1 >> %d\n", len1);
	if (test == -1) {
        printf("n/a");
    } else {
        //bubble_sort(data);
		sum(buff1, len1, buff2, len2, result, &result_length);
        output(buff1, len1, buff2, len2, result, result_length);
    }
}

int input(int *buff1, int *buff2, int *len1, int *len2) {
    char test = '0';
    for (i = 0; i < LEN && test != '\n'; i++) {
        scanf("%d%c", & *(buff1 + i), &test);
		*len1 = *len1 + 1;
        if (test != '\n' && test != ' ')
            return -1;
    }
	test = '0';
    for (i = 0; i < LEN && test != '\n'; i++) {
        scanf("%d%c", & *(buff2 + i), &test);
		*len2 = *len2 + 1;
        if (test != '\n' && test != ' ')
            return -1;
    }
	return 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    printf(">> %d\n",*(buff1 + (len1 - 1)));
	for (i = 1; i <= len1; i++) { // добавить, чтобы len выбирался тот что меньше //
		*(result + *result_length) = (*(buff1 + (len1 - i)) + *(buff2 + (len2 - i)));
		*result_length = *result_length + 1;
	}
	//printf("res_len >> %d\n", *result_length);
	for (i = 1; i <= *result_length; i++) {
		printf("RESULT >> %d\n", *(result + *result_length - i));
		if (*(result + *result_length - i ) > 9) {
			//printf("res ++ %d\n", *(result + *result_length - i));
			*(result + *result_length - i) = *(result + *result_length - i) % 10;
			//printf("res ++ %d\n", *(result + *result_length - i));
			*(result + *result_length - (i - 1)) = *(result + *result_length - (i - 1)) + 1;
		}
	}
	//if(*(result + *result_length) > )
	printf("REL >> %d \n", *result);
}

/*
int digit(int *buff1, int len1, int *buff2, int len2){
    
}
*/
void output(int *buff1, int len1, int *buff2, int len2, int *result, int result_length) {
    for (i = 0; i < len1; i++) {
        printf("%d ", *(buff1 + i));
    }
	printf("\n");
	for (i = 0; i < len2; i++) {
        printf("%d ", *(buff2 + i));
    }
	//printf("result_length >> %d", result_length);
	//printf("result >> %d", *(result));
	for (i = 0; i < result_length; i++) {
        printf("result >> %d ", *(result + i));
    }
}

void cl(int *buff1, int *buff2){
    for (i = 0; i < LEN; i++ ){
        *(buff1 + i) = 0;
		*(buff2 + i) = 0;
    }
}
