#include <stdio.h>

void print_seven_series(int num)
{
	int i = 1;

	while(i < num + 1)
	{
		if(i < num)
		{
			printf("%d\t", i * 7);
		}
		else
		{
			printf("%d\n", i * 7);
		}
		i++;
	}
}

int main(void)
{
	print_seven_series(7);
	return 0;
}
