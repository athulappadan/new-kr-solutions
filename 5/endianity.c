//	to chech the endianity

#include <stdio.h>

main()
{
	short int a = 0x1234;

	unsigned char *p;

	p = (unsigned char *)(&a);

	printf("%x\n", *p);
	printf("%x\n", *(p+1));
}

