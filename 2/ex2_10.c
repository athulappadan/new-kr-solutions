/* convert upper case letters to lower case								*/

#include <stdio.h>

int lower(int c);

main()
{
	int num;
	num = getchar();

	int converted = lower(num);
	printf("%c\n", converted);
}

int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
