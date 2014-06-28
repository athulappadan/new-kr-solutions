#include <stdio.h>
#include <string.h>
#define MAX	1000

void str_cpy(char *s, char *t, int n);
void str_cat(char *s, char *t, int n);
int str_cmp(char *s, char *t, int n);

main()
{
	int i;
        char from[MAX], to[MAX];
        scanf("%s", from);
	scanf("%s", to);

        str_cat(to, from, 3);
        for (i = 0; to[i] != '\0'; i++)
                putchar(to[i]);
        putchar('\n');

        return 0;

}

void str_cpy(char *s, char *t, int n)
{
	while (*t && n-- > 0)
		*s++ = *t++;
	while (n-- > 0)
		*s++ = '\0';
}

void str_cat(char *s, char *t, int n)
{
	int str_len(char *s);

	str_cpy(s + str_len(s), t, n);
}

int str_cmp(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0' || --n > 0)
			return 0;
	return *s - *t;
}

int str_len(char *s)
{
	int n = 0;
	while (*s++)
		n++;
	return n;
}

