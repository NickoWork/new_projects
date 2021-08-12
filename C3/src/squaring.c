#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int data[NMAX], n, test;
    test = input(data, &n);
    if (test == -1) {
        printf("n/a");
    } else {
        squaring(data, n);
        output(data, n);
    }

    return 0;
}

int input(int *a, int *n) {
    int check_ar2 = 0, count = 0;
    char check, check_ar1;
    if (scanf("%d%c", n, &check) != 2 || check != '\n' )
        return -1;

    for (int *p = a; p - a < *n; p++) {
        check_ar2 += scanf("%d%c", p, &check_ar1);
        if (check_ar1 != '\n' && check_ar1 != ' ')
            return -1;
        count++;
    }
    if (check_ar2 != count*2)
        return -1;
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ",  a[i]);
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++)
        a[i] = a[i]*a[i];
}


