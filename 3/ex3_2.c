#include <stdio.h>

#define MAX 1000

void get_string(char t[]);
void escape(char s[], char t[]);
void unescape(char t[], char s[]);

main()
{
	char to[MAX];
	char from[MAX];

	get_string(from);						/* reading string into 'from'	*/

	printf("first function: displaying escape sequences\n");
	escape(to, from);						/* copying from - to displaying escape sequences	*/
	putchar('\n');

	printf("second function : removing escape sequences\n");	/* copy back to - from removing escape sequences	*/
	unescape(from, to);

	return 0;
}

void get_string(char t[])
{
	int c,i;
	i = 0;

	while ((c = getchar()) != EOF) {
		t[i] = c;
		++i;
	}
	t[i] = '\0';
}

void escape(char s[], char t[])
{
	int i,j;
	
	for (i = j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
		
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;

		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;

		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';

	for (j = 0; s[j] != '\0'; ++j)
		putchar(s[j]);
	putchar('\n');
}

void unescape(char t[], char s[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; ++i) {

		if (s[i] != '\\')
			t[j++] = s[i];

		else {
			switch (s[++i]) {
			
			case 'n':
				t[j++] = '\n';
				break;

			case 't':
				t[j++] = '\t';
				break;
			default:
				t[j++] = '\\';
				t[j++] = s[i];
				break;
			}
		}
	}
	t[j] = '\0';

	for (i = 0; i < j; ++i)
		putchar(t[i]);
	putchar('\n');
}

