/* squeeze : to delete char in s1 which is present in s2							*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
	char str1[20], str2[20];

	printf("Enter 1st string: ");
	scanf("%s", str1);

	printf("Enter 2nd string: ");
	scanf("%s", str2);
	
	squeeze(str1, str2);

	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = k = 0; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';

	for (i = 0; s1[i] != '\0'; ++i)
		putchar(s1[i]);
	printf("\n"); 
}

