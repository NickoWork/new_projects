#include "data_stat.h"

double max(double *a, int n) {
	int max;
	max = a[0];
	for (int i = 0; i < n ; i++) {
        if (a[i] > max)
            max = a[i];
	}
    return max;
}

double min(double *a, int n) {
	int min;
	min = a[0];
	for (int i = 0; i < n ; i++) {
        if (a[i] < min)
            min = a[i];
	}
    return min;
}

double mean(double *a, int n){
    double mean = 0;
    for (int i = 0; i < n ; i++) {
        mean += a[i];
	}
    mean /= n;
	return mean;
}

double variance(double *data, int n) {
  double var_v;
  double svar = 0;
  double q = mean(data, n);
  for (int i = 0; i < n; i++) {
    svar = svar + ((data[i]) * (data[i]));
  }
  var_v = svar / n - q * q;
  return var_v;
}