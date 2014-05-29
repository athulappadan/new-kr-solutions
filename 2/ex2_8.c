unsigned rightrot(unsigned x, int n)
{

	int rbit;

	while (n-- > 0){
		rbit = (x & 1) << (wordlength(x) - 1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

int wordlength(unsigned b)
{
	int i;

