#include <stdio.h>
#include <math.h>

float important_function(float x);

int main()
{
	int check = 0;
	float x;
	check = scanf("%f", &x);
	if (check != 1)
	{
		printf("n/a");
	}
	else 
	{
		if (x == (int)x)
		{
			printf("%.1f", important_function(x));
		}
		else printf("n/a");
	}
}

float important_function(float x){
	x = (7e-3 * pow(x,4) + ((22.8 * pow(x,(1/3)) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x),(2/x)) - 1.01);
	return x;
}
