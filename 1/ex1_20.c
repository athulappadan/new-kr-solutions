#include <stdio.h>

#define TABING 8

main()
{
	int nb, pos, c;
	pos = 1;

	while ((c = getchar()) != EOF){
		nb = TABING - (pos - 1) % TABING;
		if (c == '\t'){
			while (nb > 0){
				putchar(' ');
				++pos;
				--nb;
			}
		}

		else if (c == '\n'){
			putchar(c);
			pos = 1;
		}
		else {
			putchar(c);
			++pos;
		}
	}

	return 0;
}

