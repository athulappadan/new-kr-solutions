#include <stdio.h>

#define MAX 1000

void get_string(char s1[]);
void expand(char s1[], char s2[]);

main()
{
	char str1[MAX];
	char str2[MAX];

	get_string(str1);		/* reading the input into str1	*/

	expand(str1, str2);		/* prints the expanded version	*/

	putchar('\n');

	return 0;
}

void get_string(char s1[])
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF; ++i) 
		s1[i] = c;

	s1[i] = '\0';
}

void expand(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0') {
		if (s1[i] == '-' && s1[i+1] > c) {
			i++;
			while ( c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
		s2[j] = '\0';
	}

	for (i = 0; s2[i] != '\0'; ++i)
		putchar(s2[i]);					/* print s2	*/
}
