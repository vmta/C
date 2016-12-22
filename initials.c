#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			printf("%c", toupper(argv[i][0]));
		}
	} else {
		//printf("Enter your name: ");
		
		int size = 128;
		char buff[size];
		char* ch;
		
		fgets(buff, size, stdin);
		
		ch = strtok(buff, " ");
		while(ch != NULL)
		{
			printf("%c", toupper(ch[0]));
			ch = strtok(NULL, " ");
		}
	}
	printf("\n");
	
	return 0;
}
