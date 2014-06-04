#include <stdio.h>

#define MAX 10000
#define abs(x)  ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w);
void reverse(char s[]);

main()
{
        int number, width;
        char str[MAX];

        printf("Enter the number: ");
        scanf("%d", &number);                   /* reading the number to be displayed   */

	printf("Enter the width: ");
	scanf("%d", &width);

        itoa(number, str, width);                    /* converting integer to string         */

        return 0;
}

void itoa(int n, char s[], int w)
{
        int i, sign;

        i = 0;
        sign = n;                               /* to know positive/negative            */

        do {
                s[i++] = abs(n % 10) + '0';
        } while ((n = n/10) != 0);

        if (sign < 0)
                s[i++] = '-';

	while (w-- > 0)				/* pad with blanks			*/
		s[i++] = ' ';
                                                                                                                       
       s[i] = '\0';

        for (i= 0; s[i] != '\0'; ++i)           /* reveresed string                     */
                putchar(s[i]);
        putchar('\n');

        reverse(s);                             /* actual output                        */
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
                temp = s[j];                            /* swapping                             */
                s[j] = s[i];
                s[i] = temp;
                ++j;
                --i;
        }

        for (i = 0; s[i] != '\0'; ++i)
                putchar(s[i]);


        putchar('\n');
}

