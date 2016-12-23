#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

	if (argc == 2)
	{
		int k = atoi(argv[1]);
		
		char unencodedText[1024];
		fgets(unencodedText, sizeof(unencodedText), stdin);
		
		char encodedText[strlen(unencodedText) - 1];
		for (int i = 0, n = strlen(unencodedText) - 1; i < n; i++)
		{
			if (unencodedText[i] >= 'A' && unencodedText[i] <= 'Z')
			{
				encodedText[i] = (char) ('A' + ((int) unencodedText[i] - 'A' + k) % ('Z' - 'A' + 1));
			} 
			else if (unencodedText[i] >= 'a' && unencodedText[i] <= 'z')
			{
				encodedText[i] = (char) ('a' + ((int) unencodedText[i] - 'a' + k) % ('z' - 'a' + 1));
			}
			else
			{
				encodedText[i] = unencodedText[i];
			}
		}
		
		printf("%s\n", encodedText);
		return 0;
	}
	else
	{
		printf("Usage: ./caesar key");
		return 1;
	}
}