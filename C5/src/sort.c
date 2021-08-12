// Copyright 2021 tprobius
#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int *data = NULL;
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        data = (int *)malloc(n * sizeof(int));
        if (input(data, &n) != 0) {
            sort(data, n);
            output(data, n);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}

int input(int *a, int *n) {
    int check = 1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            check = 0;
        } else {
            check = 1;
        }
    }
    return check;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void sort(int *a, int n) {
    int tmp;
    for (int *p = a; p - a < n; p++) {
        for (int *p = a; p - a < n - 1; p++) {
            if (*p > *(p + 1)) {
                tmp = *(p + 1);
                *(p + 1) = *p;
                *p = tmp;
            }
        }
    }
}
