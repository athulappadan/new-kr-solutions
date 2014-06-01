#include <stdio.h>

#define MAX 1000

void get_string(char t[]);
void escape(char s[], char t[]);

main()
{
	char to[MAX];
	char from[MAX];

	get_string(from);
	escape(to, from);

	return 0;
}

void get_string(char t[])
{
	int c,i;
	i = 0;

	while ((c = getchar()) != EOF) {
		t[i] = c;
		++i;
	}
	t[i] = '\0';
}

void escape(char s[], char t[])
{
	int i,j;
	
	for (i = j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
		
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;

		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;

		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';

	for (j = 0; s[j] != '\0'; ++j)
		putchar(s[j]);
	putchar('\n');
}
