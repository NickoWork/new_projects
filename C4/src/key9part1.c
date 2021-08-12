/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *numbers, int number, int count);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

int i;

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особсую сумму
	и сформированных массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int buffer[NMAX], numbers[NMAX], length, sum_num, count, check = 0;
    check = input(buffer, &length);
    if (check == -1) {
        printf("n/a");
    } else {
        sum_num = sum_numbers(buffer, length);
        count = find_numbers(buffer, length, sum_num, numbers);
        output(numbers, sum_num, count);
    }
}

int input(int *buffer, int *length) {
    char check1, check2;
    int check = 0;
    scanf("%d%c", & *length, &check1);
    if (check1 != '\n' && check1 != ' ')
        return -1;
    for (i = 0; i < *length; i++) {
        check += scanf("%d%c", & *(buffer + i), &check2);
        if (check2 != ' ' && check2 != '\n')
            return -1;
    }
    if (check != (*length)*2)
        return -1;
    return 0;
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
    int count = 0;
    for (i = 0; i < length; i++) {
        if (*(buffer + i) != 0) {
            if (number % *(buffer + i) == 0) {
                *(numbers + count) = *(buffer + i);
                count++;
            }
        }
    }
    return count;
}

void output(int *numbers, int number, int count) {
    if (number == 0) {
        printf("n/a");
    } else {
        printf("%d\n", number);
        for (i = 0; i < count; i++) {
        printf("%d ", *(numbers + i));
        }
    }
}
