#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n;
	
	if (argc > 1)
	{
		n = strtol(argv[1], NULL, 10);
	} else {
		do
		{
			printf("height: ");
			scanf("%d", &n);
			printf("You entered: %d\n", n);
		} while (n < 1 || n > 23);
	}
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
	return 0;
}
