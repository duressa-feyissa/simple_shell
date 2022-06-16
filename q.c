#include "_string.h"

/**
 * _strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string
 * Return: int
 */
int _atoi(char *s)
{
	unsigned int len = 0, size = 0, p = 1, res = 0, sign = 1, i = 0;

	while (*(s + len) != '\0')
	{
		if (size > 0 && (*(s + len) < '0' || *(s + len) > '9'))
			break;

		if (*(s + len) == '-')
			sign *= -1;

		if ((*(s + len) >= '0') && (*(s + len) <= '9'))
		{
			if (size > 0)
				p *= 10;

			size++;
		}
		len++;
	}

	for (i = len - size; i < len; i++)
	{
		res += ((*(s + i) - '0') * p);
		p /= 10;
	}

	return (sign * res);
}

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

/**
 * _itoa - get the length of an integer
 * @n: given integer
 * Return: length of integer
 */
char *_itoa(int n)
{
	unsigned int n1;
	int length = _intlen(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + length) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	length--;
	do {
		*(buffer + length) = (n1 % 10) + '0';
		n1 = n1 / 10;
		length--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

/**
 * _isdigit - checks if a char is a digit
 *
 * @str: string to check
 * Return: returns 1 if digit and 0 if not a digit
 */

int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
