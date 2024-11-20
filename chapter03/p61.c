/*
edit the code below to ensure that no attempt of reading from a null address occurs:
long cread(long *xp) {
return (xp ? *xp : 0);
}
*/

long cread_alt(long *xp)
{
	long result = 0.0;
	
	// only proper way of ensuring not derefrencing NULL pointer
	// will need to use some higher optimization level to possibly get cmove instruction
	if (xp) {
		result = *xp;
	}

	return result;
}
