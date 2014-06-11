#include <stdio.h>

#define MAXLINE 100

main()
{
	double sum, atof(char s[]);
	char line[MAXLINE];
	int get_line(char line[], int maxline);

	sum = 0;
	while (get_line(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));

	return 0;
}

