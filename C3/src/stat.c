#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n, double mean);
void output_res(int max, int min, double mean, double variance);
int i;

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX], test;
	int max_v, min_v;
    double mean_v, variance_v;
	test = input(data, &n);
    if (test == -1) {
        printf("n/a");
    } else {
        output(data, n);
		max_v = max(data, n);
		min_v = min(data, n);
		mean_v = mean (data, n);
		variance_v = variance(data, n, mean_v);
        output_res(max_v, min_v, mean_v, variance_v);
//        output_result(max(data, n),
//                      min(data, n),
//                      mean(data, n),
//                      variance(data, n));
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

int max(int *a, int n) {
	int max;
	max = a[0];
	for (i = 0; i < n ; i++) {
        if (a[i] > max)
            max = a[i];
	}
    return max;
}

int min(int *a, int n) {
	int min;
	min = a[0];
	for (i = 0; i < n ; i++) {
        if (a[i] < min)
            min = a[i];
	}
    return min;
}

double mean(int *a, int n){
    double mean = 0;
    for (i = 0; i < n ; i++) {
        mean += a[i]; 
	}
    mean /= n;
	return mean;
}

double variance(int *a, int n, double mean) {
    double variance = 0;
	double mx = 0;
    for (i = 0; i < n ; i++) {
        mx += a[i]*a[i];
    	printf("mx >> %f", mx);
	}
    variance = mx - mean * mean;
	return variance;
}

void output_res(int max, int min, double mean, double variance) {
    printf("max >> %d\n", max);
	printf("min >> %d\n", min);
    printf("mean >> %.6f\n", mean);
	printf("variance >> %.6f\n", variance );
} 
