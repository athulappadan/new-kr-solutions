#include <stdio.h>

#define TABINC 8

main()
{
	int nb, pos, c;

	nb = 0;
	pos = 0;

	while((c = getchar()) != EOF){
		if(c == ' '){
			++nb;
			if ((nb + pos) % TABINC == 0){
				putchar('\t');
				nb = (nb + pos) % TABINC;
				pos = 0;
			}
		}

		else {
			pos = 0;
			while (nb > 0) {
				putchar(' ');
				--nb;
			}
			putchar(c);
			++pos;
		}
		
	}
	return 0;
}
