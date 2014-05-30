/* to invert n bits starting at position p		*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

main()
{
	unsigned num;

	printf("Enter the binary number: ");
	scanf("%u", &num);
	unsigned inv_num = invert(num, 2, 1);

	printf("Inverted number is: %u\n", inv_num);
}

unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}

