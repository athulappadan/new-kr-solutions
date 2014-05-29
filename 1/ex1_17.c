
#include <stdio.h>
#define MAXLINE 1000
#define MIN 5

int get_line(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0){
		if (len > MIN)
			printf("%s", line);
	}
	return 0;
}

int get_line(char s[], int limit)
{
	int c, i;

	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	
	return i;
	
}
