
#include <ctype.h>


double atof (char s[])
{
	double value, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)				/* Skip the leading blanks		*/
		;
	
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (value = 0.0; isdigit(s[i]); i++)			/* Integer part				*/
		value = 10.0 * value + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++) {			/* Fractional part			*/
		value = 10.0 * value + (s[i] - '0');
		power *= 10.0;
	}

	return sign * value / power;
}

