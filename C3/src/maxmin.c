// Copyright[2021] <Copyright awoolfie>

#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilities */
int main() {
    int x, y, z, check;
    char check_last;
    int max, min, disp, exp ;
    check = (scanf("%d%d%d%c", &x, &y, &z, &check_last));
    if (check != 3 && check_last != '\n') {
        printf("n/a");
    } else {
         maxmin(x, y, z, &max, &min);
         printf("%d %d", max, min);
    }

    return 0;
}


/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;
    if (prob2 > *max)
        *max = prob2;
    if (prob2 < *min)
        *min = prob2;
    if (prob3 > *max)
        *max = prob3;
    if (prob3 < *min)
        *min = prob3;
}
