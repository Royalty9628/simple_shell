include "main.h"

/**
 * _strdup - duplicates a str in the heap memory
 * @s: Type char pointer str
 * Return: Duplicated str
 */

char *_strdup(const char *s)
{
	char *new;
	size_t lent;

	lent = _strlen(s);
	new = malloc(sizeof(char) * (lent + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, lent + 1);
	return (new);
}


/**
 * _strlen - function that returns the length of a string
 * @s: Type char pointer
 * Return: Always 0
 */

int _strlen(const char *s)
{
	int lent;

	for (lent = 0; s[lent] != 0; lent++)
	{
	}
	return (lent);
}


/**
 * cmp_chars - copare chars of string
 * @str: input string
 * @delim: delimiter
 * Return: 1 if are equals, 0 if not
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int ro, da, rd;

	for (ro = 0, rd = 0; str[ro]; ro++)
	{
		for (da = 0; delim[da]; da++)
		{
			if (str[ro] == delim[da])
			{
				rd++;
				break;
			}
		}
	}
	if (ro == rd)
		return (1);
	return (0);
}


/**
 * _strtok - splits a string by some delimeter
 * @str: input string
 * @delim: delimiter
 * Return: string splited
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int j, Rose;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		j = _strlen(str);
		str_end = &str[j];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);
	for (Rose = 0; *splitted; splitted++)
	{
		if (splitted && *(splitted - 1) == '\0')
			break;
		for (j = 0; delim[j]; j++)
		{
			if (*splitted == delim[j])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (Rose == 0 && *splitted)
			Rose  = 1;
	}
	if (Rose == 0)
		return (NULL);
	return (str_start);
}


/**
 * _isdigit - defines if string passed is a number
 * @s: input string
 * Return: if string is a number, 0 in other cases
 */

int _isdigit(const char *s)
{
	unsigned int rd;

	for (rd = 0; s[rd]; rd++)
	{
		if (s[rd] < 48 || s[rd] > 57)
			return (0);
	}
	return (1);
}
