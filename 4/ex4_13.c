#include <stdio.h>
#include <string.h>
#define MAX 100

void reverse(char s[]);

main()
{
	char str[MAX];
	int i = 0;

	printf("Enter the string\n");
	scanf("%s", str);

	reverse(str);
	while (str[i] != '\0')
		putchar(str[i++]);
	putchar('\n');

	return 0;
}

void reverse(char s[])
{
	void reverser(char s[], int i, int len);

	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
	int c, j;

	j = len - (i+1);
	if (i < j) {
		c = s[i];
		s[i] =s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}

