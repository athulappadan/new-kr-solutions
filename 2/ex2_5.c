/*	any; to find the first occurance of a substring							*/

#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
	char str1[20], str2[20];				/* reading the two strings		*/
	
	printf("Enter 1st string: ");
	scanf("%s", str1);

	printf("Enter 2nd string: ");
	scanf("%s", str2);

	int first_index = any(str1, str2);			/* returned value of first occurance	*/

	printf("Position of first occurance is: %d\n", first_index);
}

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
		
	return -1;
}
