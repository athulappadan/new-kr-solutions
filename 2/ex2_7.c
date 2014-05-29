/* to invert n bits starting at position p		*/

unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}

