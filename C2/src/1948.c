#include <stdio.h>

int ssem(int a);

int main() {
	float cache;
	int test;
	scanf("%f", &cache);
	if ((int)cache != cache ||  cache == 0)
		printf("n/a");
	else
		printf("%d", ssem(cache));
}

int ssem(int cache) {
	int a, i, j, z, tmp, check, k = 0, count = 0;
	a = cache;
	if (a < 0)
		a *= (-1);
	tmp = a;
	for (i = 2; i < a; i++) {
		tmp = a;
		while (tmp > 0) {
			tmp = tmp - i;
			if (tmp == 0) {
					for (j = 2; j <= 10; j++) {
						for (z = 2; (z <= 10); z++) {
							check = z * j;
							if (check == i)
									k++;
						}
					}
					if ((i > count) && (k == 0))
						count = i;
					k = 0;
			}
		}
	}
	return count;
}
