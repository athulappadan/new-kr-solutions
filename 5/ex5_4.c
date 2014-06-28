#include <stdio.h>
#define MAX	1000

int str_end(char *s, char *t);
main()
{
	int match;
	char one[MAX], two[MAX];

	scanf("%s", one);
	scanf("%s", two);
	printf("%d\n", match = str_end(one, two));

	return 0;
}
int str_end(char *s, char *t)
{
	char *bs = s;
	char *bt = t;

	for (; *s; s++)
		;
	for (; *t; t++)
		;

	for (; *s == *t; s--, t--) 
		if (t == bt || s == bs)
			break;
	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
}

