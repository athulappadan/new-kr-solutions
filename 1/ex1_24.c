#include <stdio.h>

int brace, bracket, paren;

void search(int c);
void in_comment(void);
void in_quote(int c);

main()
{
	int c;
	extern int brace, bracket, paren;

	while ((c = getchar()) != EOF){

		if (c == '/'){
			if ((c = getchar()) == '*')
				in_comment();
			else
				search(c);

		}
		else if (c == '\'' || c == '"')
			in_quote(c);

		else
			search(c);

		if (brace < 0){
			printf("unbalnced brace\n");
			brace = 0;
		}
		
		else if (bracket < 0){
			printf("unbalanced bracket\n");
			bracket = 0;
		}
	
		else if (paren < 0){
			printf("unbalanced paren\n");
			paren = 0;
		}
	}

	if (brace > 0)
		printf("unbalnced brace\n");
	if (bracket > 0)
		printf("unbalanced bracket\n");
	else if (paren > 0)
		printf("unbalanced paren\n");

}

void search(int c)
{
	if (c == '{')
		++brace;
	else if (c == '}')
		--brace;
	else if (c == '[')
		++bracket;
	else if (c == ']')
		--bracket;
	else if (c == '(')
		++paren;
	else if (c == ')')
		--paren;
}

void in_comment(void)
{
	int c, d;

	c = getchar();
	d = getchar();

	while (c != '*' || c != '/'){
		c = d;
		d = getchar();
	}
}

void in_quote(int c)
{
	int d;

	while ((d = getchar()) != c){
		if (d == '\\')
			getchar();
	}
}

