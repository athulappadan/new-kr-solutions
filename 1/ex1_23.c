#include <stdio.h>

void rcomment(int c);
void incomment(void);
void echoquote(int c);

main()
{
	int c;
	while ((c = getchar()) != EOF)
		rcomment(c);
	return 0;
}

void rcomment(int c)
{
	int d;

	if (c == '/'){
		if ((d = getchar()) == '*')
			incomment();
		else if (d == '/'){
			putchar(c);
			rcomment(d);
		}
		else {
			putchar(c);
			putchar(d);
		}
	}

	else if (c == '\'' || c == '"')
		echoquote(c);

	else
		putchar(c);

}

void incomment(void)
{
	int c, d;

	c = getchar();
	d = getchar();

	while (c != '*' || d != '/'){
		c = d;
		d = getchar();
	}

}

void echoquote(int c)
{
	int d;
	putchar(c);

	while ((d = getchar()) != c){
		putchar(d);
		if (d == '\\')
			putchar(getchar());
	}
	putchar(d);

}

