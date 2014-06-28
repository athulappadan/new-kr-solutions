#include <stdio.h>
#define MAX	1000

void str_cat(char *s, char *t);

main()
{
	int i;
	char one[MAX], two[MAX];

	scanf("%s", one);
	scanf("%s", two);

	str_cat(one, two);
	for (i = 0; one[i] != '\0'; i++)
		putchar(one[i]);
	putchar('\n');

	return 0;
}
void str_cat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

