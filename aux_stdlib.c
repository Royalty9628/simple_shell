#include "main.h"

/**
 * get_len - get the length of a number
 * @n: type int number
 * Return: Length of a number
 */

int get_len(int n)
{
	unsigned int da;
	int lent = 1;

	if (n < 0)
	{
		lent++;
		da = n * -1;
	}
	else
	{
		da = n;
	}
	while (da > 9)
	{
		lent++;
		da = da / 10;
	}
	return (lent);
}


/**
 * aux_itoa - function that convert int to string
 * @n: type int number
 * Return: String
 */

char *aux_itoa(int n)
{
	unsigned int da;
	int lent = get_len(n);
	char *buffer;

	buffer  = malloc(sizeof(char) * (lent + 1));
	if (buffer == 0)
		return (NULL);
	*(buffer + lent) = '\0';
	if (n < 0)
	{
		da = n * -1;
		buffer[0] = '-';
	}
	else
	{
		da = n;
	}
	lent--;
	do {
		*(buffer + lent) = (da % 10) + '0';
		da = da / 10;
		lent--;
	}
	while (da > 0)
		;
	return (buffer);
}


/**
 * _atoi - convert a tring to an integer
 * @s: input string
 * Return: integer
 */

int _atoi(char *s)
{
	unsigned int count  = 0, size = 0, da = 0, ro = 1, rd = 1, j;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '\0' || *(s + count) > '9'))
			break;
		if (*(s + count) == '-')
			ro = ro * -1;
		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				rd = rd * 10;
			size++;
		}
		count++;
	}
	for (j  = count - size; j < count; j++)
	{
		da = da + ((*(s + j) - 48) * rd);
		rd = rd / 10;
	}
	return (da * ro);
}
