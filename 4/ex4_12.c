#include <stdio.h>
#include <math.h>

#define MAX 	100

void itoa(int n, char s[]);

main()
{
	int num, j;
	char str[MAX];
	j = 0;

	printf("Enter the number: \n");
	scanf("%d", &num);

	printf("The string is:\n");
	itoa(num, str);
	while (str[j] != '\0')
		putchar(str[j++]);
	putchar('\n');

	return 0;
}

void itoa(int n, char s[])
{
	static int i;

	if (n/10)
		itoa(n/10, s);

	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

