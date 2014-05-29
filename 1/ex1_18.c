
#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int maxline);
int remove_space(char s[]);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0){
		remove_space(line);
		printf("%s", line);
	}
	return 0;
}

int get_line(char s[], int limit)
{
	int i, c;
	i = 0;

	while ((c = getchar()) != EOF && c != '\n'){
		s[i] = c;
		++i;
	}
	if (c = '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

int remove_space(char s[])
{
	int i = 0;

	while (s[i] != '\n')
		++i;
	--i;
	while (i > 0 && (s[i] != ' ' || s[i] != '\t')){
		--i;
		if (i > 0 && (s[i] == ' ' || s[i] == '\t'){
			s[i] = '\n';
		}
	}
	return i;
} 
