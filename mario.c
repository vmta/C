#include <stdio.h>
int main(void)
{
	int n;
	do
	{
		printf("Enter positive integer number below 23:");
		scanf("%d", &n);
		printf("You entered: %d\n", n);
	} while (n < 1 || n > 23);

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (j > i)
			{
				printf(" ");
			} else {
				printf("#");
			}
		}
		printf("##\n");
	}
}
