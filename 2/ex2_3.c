#include <stdio.h>

#define MAX 50
enum boolean { NO, YES };

int htoi(char s[]);

main()
{
	char input[MAX];
	printf("enter the hex number: ");
	scanf("%s", input);

	int p = htoi(input);
	printf("%d\n", p);

	return 0;
		
}	

int htoi(char s[])
{
	int i, hexdigit, inhex, n;
	i = 0;

	if (s[i] == '0'){
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	n = 0;
	inhex = YES;

	for ( ; inhex == YES; ++i){
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'z')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

