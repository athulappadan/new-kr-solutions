#include <stdlib.h>

#define MAXLINE	100
#define TABING	8
#define YES	1
#define	NO	0

void settab(int argc, char *argv[], char *tab)
{
	int i, pos;

	if (argc <= 1)
		for (i = 1; i <= MAXLINE; i++)
			if (i % TABING == 0)
				tab[i] = YES;
			else
				tab[i] =NO;

	else {
		for (i = 1; i <= MAXLINE; i++)
			tab[i] = NO;
		while (--argc > 0) {
			pos = atoi(*++argv);
			if (pos > 0 && pos <= MAXLINE)
				tab[pos] = YES;
		}
	}
}

int tabpos(int pos, char *tab)
{
	if (pos > MAXLINE)
		return YES;
	else
		return tab[pos];
}

