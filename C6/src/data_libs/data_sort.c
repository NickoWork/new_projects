#include"data_sort.h"

void sort(double *data, int n) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (*(data + j) > *(data + (j + 1))) {
                tmp = *(data + (j + 1));
                *(data + (j + 1)) = *(data + j);
                *(data + j) = tmp;
            }
        }
    }
}
