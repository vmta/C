#include <stdio.h>
#include <math.h>

int DEBUG = 0;

float getChange()
{
	float _change;
	
	int buff_size = 64;
	char buffer[buff_size];
	
	do
	{		
		printf("O hai! How much change is owed?\n");
		fgets(buffer, buff_size, stdin);
		
		sscanf(buffer, "%f", &_change);
//		if (sscanf(buffer, "%f", &_change) == 1)
//		{
//			break;
//		}

		if (DEBUG)
		{
			printf("You entered %f: \n", _change);
		}
	} while(_change <= 0);
	
	return _change;
}

int main(int argc, char *argv[])
{
	float change;
	int coins = 0;
	
	if (argc > 1)
	{
		sscanf(argv[1], "%f", &change);
	} else {
		change = getChange();
		
	}
	
	int cents = round(change * 100);
	if(DEBUG)
	{
		printf("change: %f, cents: %d\n", change, cents);
	}
	
	int quarter = 0;
	while (cents >= 25)
	{
		cents -= 25;
		coins++;
		if (DEBUG)
		{
			quarter++;
			printf("Cents left: %d, coins given %d.\n", cents, coins);
		}
	}
	
	int dime = 0;
	while (cents >= 10)
	{
		cents -= 10;
		coins++;
		if (DEBUG)
		{
			dime++;
			printf("Cents left: %d, coins given %d.\n", cents, coins);
		}
	}
	
	int nickel = 0;
	while (cents >= 5)
	{
		cents -= 5;
		coins++;
		if (DEBUG)
		{
			nickel++;
			printf("Cents left: %d, coins given %d.\n", cents, coins);
		}
	}
	
	int penny = 0;
	while (cents > 0)
	{
		cents -= 1;
		coins++;
		if (DEBUG)
		{
			penny++;
			printf("Cents left: %d, coins given %d.\n", cents, coins);
		}
	}
	
	printf("%d\n", coins);
	
	if (DEBUG)
	{
		printf("Change of %f requires total of %d coins.\n", change, coins);
		printf("%d quarters\n", quarter);
		printf("%d dimes\n", dime);
		printf("%d nickels\n", nickel);
		printf("%d pennys\n", penny);
	}
}
