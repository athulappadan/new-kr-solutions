#include <ctype.h>

/* atof: converting string to double with 'E'			*/

double atof(char s[])
{
	double value, power;
	int i, sign, exp;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (value = 0.0; isdigit(s[i]); i++)
		value = 10.0 * value + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		value = 10.0 * value + (s[i] -'0');
		power *= 10;
	}

	value = sign * value / power;

	if (s[i] == 'e' || s[i] == 'E') {

		sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
	
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');


		if (sign == 1) 
			while (exp-- > 0)
				value *= 10;

		else 
			while (exp-- > 0)
				value /= 10;
	}

	return value;

}
