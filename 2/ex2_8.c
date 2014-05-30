#include <stdio.h>

unsigned rightrot(unsigned x, int n);

main()
{
	unsigned input;
	printf("Enter the number: ");
	scanf("%u", &input);
	unsigned rot_num = rightrot(input, 2);

	printf("The rotated number is: %u\n", rot_num);
}

unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbit;

	while (n-- > 0){
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}
