#include <stdio.h>
#define NMAX 10

int i;

int input(int *data);
void bubble_sort(int *data);
void output(int *data);

int main() {
    int data[NMAX], test, a;
    test = input(data);
    if (test == -1) {
        printf("n/a");
    } else {
        bubble_sort(data);
        output(data);
    }
}

int input(int *data) {
    char test;
    int check = 0;
    for (i = 0; i < NMAX; i++) {
        check += scanf("%d%c", & *(data + i), &test);
        if (test != '\n' && test != ' ')
            return -1;
    }
    if (check != 20)
        return -1;
    return 0;
}

void bubble_sort(int *data) {
    int tmp = 0;
    int j = 0;
    for (i = 0; i < NMAX; i++) {
        for (j = 0; j < NMAX-1; j++) {
            if (*(data + j) > *(data + (j + 1))) {
                tmp = *(data + (j + 1));
                *(data + (j + 1)) = *(data + j);
                *(data + j) = tmp;
            }
        }
    }
}

void output(int *data) {
    for (i = 0; i < NMAX; i++) {
        printf("%d ", *(data + i));
    }
}
