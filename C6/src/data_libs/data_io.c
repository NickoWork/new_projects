#include<stdio.h>
#include"data_io.h"

void input(double *a, int n) {

    for (int i = 0; i < n; i++) 
        scanf("%lf", &*(a + i));
}

void output(double *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%.2lf ",  a[i]);
}
