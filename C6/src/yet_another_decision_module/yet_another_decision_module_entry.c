#include<stdio.h>
#include<stdlib.h>
#include"decision.h"
#include"../data_libs/data_io.h"

int main()
{
    double *data;
    int n;
    data = (double*) malloc(n * sizeof(double));
    scanf("%d", &n);
    input(data, n);
    if (make_decision(data, n))
        printf("YES"); 
    else
        printf("NO");  
}
