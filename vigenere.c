#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	int DEBUG = 0;
	
	if (argc == 2)
	{
		char* k = argv[1];
		for (int i = 0, n = strlen(k); i < n; i++)
		{
			if(isalpha(k[i]) == 0) {
				printf("Usage: ./vigenere key\nKey must contain only letters from Aa to Zz.\n");
				return 1;
			}
		}
		
		int size = 8192;
		char unencodedText[size];
		char encodedText[size];
		fgets(unencodedText, sizeof(unencodedText), stdin);
		
		for (int i = 0, j = 0, n = strlen(unencodedText) - 1; i < n; i++)
		{
			int jj = j % strlen(k);
			
			if (unencodedText[i] >= 'A' && unencodedText[i] <= 'Z')
			{
				encodedText[i] = (char) ('A' + ((int) unencodedText[i] - 'A' + toupper(k[jj]) - 'A') % ('Z' - 'A' + 1));
				if(DEBUG)
				{
					printf("i: %d unencodedText[%d]: %c; ", i, i, unencodedText[i]);
					printf("j: %d k[%d]: %c; ", j, j, toupper(k[jj]));
					printf("encodedText[%d]: %c\n", i, encodedText[i]);
					
					printf("%d + (%d - %d + %d - %d) modulo (%d - %d + 1) = %d\n", 'A', (int) unencodedText[i], 'A', toupper(k[jj]), 'A', 'Z', 'A', ('A' + ((int) unencodedText[i] - 'A' + toupper(k[jj]) - 'A') % ('Z' - 'A' + 1)));
				}
				j++;
			} 
			else if (unencodedText[i] >= 'a' && unencodedText[i] <= 'z')
			{
				encodedText[i] = (char) ('a' + ((int) unencodedText[i] - 'a' + tolower(k[jj]) - 'a') % ('z' - 'a' + 1));
				if(DEBUG)
				{
					printf("i: %d unencodedText[%d]: %c; j: %d k[%d]: %c\n", i, i, unencodedText[i], j, j, k[jj]);
					
					printf("%d + (%d - %d + %d - %d) modulo (%d - %d + 1) = %d\n", 'a', (int) unencodedText[i], 'a', k[jj], 'a', 'z', 'a', ('a' + ((int) unencodedText[i] - 'a' + k[jj] - 'a') % ('z' - 'a' + 1)));
				}
				j++;
			}
			else
			{
				encodedText[i] = unencodedText[i];
				if(DEBUG)
				{
					printf("i: %d unencodedText[%d]: %c; encodedText[%d]: %c\n", i, i, unencodedText[i], i, encodedText[i]);
				}
			}
		}
		printf("%s\n", encodedText);
		return 0;
	}
	else
	{
		printf("Usage: ./vigenere key\nKey must contain only letters from Aa to Zz.\n");
		return 1;
	}
}