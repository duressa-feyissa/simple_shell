#include "_string.h"

/**
 * _intlen - get the length of an integer
 * @n: given integer
 * Return: length of integer
 */
int _intlen(int n)
{
	unsigned int len = 0, m;

	if (n < 0)
	{
		len++;
		m = n * -1;
	}
	else
	{
		m = n;
	}

	if (n == 0)
		return (1);

	for (; m != 0; m /= 10)
		len++;

	return (len);
}
