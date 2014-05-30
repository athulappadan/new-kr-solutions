#include <stdio.h>

int bitcount(unsigned x);

main()
{
	unsigned num;

	printf("Enter the number: ");
	scanf("%u", &num);
	
	int ones = bitcount(num);
	printf("The number of ones is: %u\n", ones);
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= x-1)
		++b;

	return b;
}
