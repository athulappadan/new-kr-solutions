#include <stdio.h>

#define MAX 100

void itob(int n, char s[], int b);

void reverse(char s[]);

main()
{
	int decimal_no, base;
	char str[MAX];

	printf("Enter the decimal number: ");
	scanf("%d", &decimal_no);					/* reading the number to be converted		*/

	printf("Enter the base: ");
	scanf("%d", &base);						/* reading the base				*/

	itob(decimal_no, str, base);

	return 0;
}

void itob(int n, char s[], int b)
{
	int i,j, sign;
	
	i = 0;
	sign = n;

	do {
		j = n % b;
		s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
	} while ((n = n/b) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	printf("Reversed string is: ");

	for (i = 0; s[i] != '\0'; ++i)
		putchar(s[i]);
	putchar('\n');

	reverse(s);
}

void reverse(char s[])
{
	int i, j, temp;

	i = j = 0;
	
	while (s[i] != '\0')
		++i;
	--i;

	if (s[i] == '\n')
		--i;

	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		++j;
		--i;
	}

	putchar('\n');

	printf("Actual output : ");

	for (i = 0; s[i] != '\0'; ++i)
		putchar(s[i]);

	putchar('\n');
}

