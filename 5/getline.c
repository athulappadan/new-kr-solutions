#include <stdio.h>

int get_line(char s[], int limit)
{
	int i, c;
	i = 0;

	while ((c = getchar()) != EOF && c != '\n'){
		s[i] = c;
		++i;
	}
	if (c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

