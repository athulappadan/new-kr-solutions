
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char line[]);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0){
		reverse(line);
		printf("%s", line);
	}
}

int get_line(char s[], int limit)
{
        int c, i;
        
        for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if (c == '\n')
        {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
    
        return i;
}

void reverse(char s[])
{
	int i, j;
	char temp;

	while (s[i] != '\0')
		++i;
	--i;
	if (s[i] = '\n')
		--i;
	j = 0;

	while (j < i){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		++j;
		--i;
	}
}
