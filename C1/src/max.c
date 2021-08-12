#include <stdio.h>

int max(int digital_1, int digital_2);

int main()
{
	float digital_1;
	float digital_2;
	float digital_3;
	scanf("%f%f", &digital_1, &digital_2);
	if ((digital_1 == (int)digital_1) && (digital_2 == (int)digital_2))
	{
		printf("%d", max(digital_1, digital_2));
	}
	else printf("n/a");			
}

int max(int digital_1, int digital_2)
{
	if (digital_1 > digital_2)
	{
		return digital_1;
	}
	else return digital_2;
}
