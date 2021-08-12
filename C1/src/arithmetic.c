#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(){
	float a, b; 
	int tmp;
	scanf("%f%f", &a, &b);
	if ((a == (int)a) && (b == (int)b)){
		printf("%d ", sum(a, b));
		printf("%d ", subtract(a, b));
		printf("%d ", multiply(a, b));
		tmp = divide(a, b);
		if (tmp){
			printf("%d", tmp);
		} 
		else printf("n/a");
	}
	else printf("n/a");
}

int sum(int a, int b){
	return (a + b);
}

int subtract(int a, int b){
	return (a - b);
}

int multiply(int a, int b){
	return (a * b);
}

int divide(int a, int b){
	if (b != 0){
		return (a / b);
	}
	else 
		return 0;
}

