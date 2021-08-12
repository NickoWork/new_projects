#include <stdio.h>

int main(){
	int check = 0;
	float x;
	float y;
	check = scanf("%f%f", &x, &y);
	if (check != 2)
	{
		printf("n/a");
		
	}
	else
	{
		if ((x*x + y*y) < 25)
		{
			printf("GOTCHA");
		}
		else printf("MISS");
	}
}
