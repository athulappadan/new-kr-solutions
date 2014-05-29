#include <stdio.h>

#define TABINC 8
#define MAXCOL 10

int findblank(int pos);
int exptab(int pos);
int newpos(int pos);
void printline(int pos);

char line[MAXCOL];
int pos;

main()
{
	int c;
	pos = 0;

	while ((c = getchar()) != EOF){
		line[pos] = c;
		if (c == '\t')
			pos = exptab(pos);
		else if (c == '\n'){
			printline(pos);
			pos = 0;
		}
		else if (++pos >= MAXCOL){
			pos = findblank(pos);
			printline(pos);
			pos = newpos(pos);
		}
	}
	return 0;
}

int exptab(int pos)
{
	line[pos] = ' ';
	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
		line[pos] = ' ';
	if (pos < MAXCOL)
		return pos;
	else{
		printline(pos);
		return 0;
	}
}

void printline(int pos)
{
	int i;
	for (i = 0; i < pos; ++i)
		putchar(line[i]);
	if (pos > 0)
		putchar('\n');
}

int findblank(int pos)
{
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)
		return MAXCOL;
	else
		return pos + 1;
}

int newpos(int pos)
{
	int i, j;
	
	if (pos < 0 || pos >= MAXCOL)
		return 0;
	else {
		i = 0;
		for (j = pos; j < MAXCOL; ++j){
			line[i] = line[j];
			++i;
		}
		return i;
	}
}

