#include <stdio.h>
#define MAX 50

void squeeze(char s[], int c);

main()
{
	char word[MAX];
	int x, i;

	for (i = 0; i < MAX && (x = getchar()) != EOF && x != '\n'; ++i)
		word[i] = x;
	if (x == '\n'){
		word[i] = x;
		++i;
	}
	word[i] = '\0';

	squeeze(word[MAX], 'a');
}

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';

	for (i = 0; i <= j; i++)
		putchar(s[i]);
}
