#include <stdio.h>
#define NMAX 10

int input(int *data, int *len, int *cycle);
void output(int *data, int len);
void shift(int *data, int len, int cycle);
int find_numbers(int* data, int len, int number, int* numbers);

int i;

int main() {
    int data[NMAX], len, count, cycle, check = 0;
    check = input(data, &len, &cycle);
    if (check == -1) {
        printf("n/a");
    } else {
        shift(data, len, cycle);
        output(data, len);
    }
}

int input(int *data, int *len, int *cycle) {
    char check1, check2, check3;
    int check = 0;
    scanf("%d%c", & *len, &check1);
    if (check1 != '\n' && check1 != ' ')
        return -1;
    for (i = 0; i < *len; i++) {
        check += scanf("%d%c", & *(data + i), &check2);
        if (check2 != ' ' && check2 != '\n')
            return -1;
    }
    if (check != (*len)*2)
        return -1;
    scanf("%d%c", & *cycle, &check3);
    if (check3 != '\n' && check3 != ' ')
        return -1;
    return 0;
}

void shift(int *data, int len, int cycle) {
    int j, tmp = 0;
    if (cycle >= 0) {
        for (j = 0; j < cycle; j++) {
            for (i = 0; i < len - 1; i++) {
                tmp = *(data + i);
                *(data + i) = *(data + i + 1);
                *(data + i + 1) = tmp;
            }
        }
    } else {
        cycle *= -1;
        for (j = 0; j < len - cycle; j++) {
            for (i = 0; i < len - 1; i++) {
                tmp = *(data + i);
                *(data + i) = *(data + i + 1);
                *(data + i + 1) = tmp;
            }
        }
    }
}
void output(int *data, int len) {
    printf("%d\n", len);
    for (i = 0; i < len; i++) {
        printf("%d ", *(data + i));
    }
}
