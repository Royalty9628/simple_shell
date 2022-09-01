#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: char pointer to the dest of the copied str
 * @src: const char pointer to the source of the str
 * Return: the dest
 */

char *_strcat(char *dest, const char *src)
{
	int r, d;

	for (r = 0; dest[r] != '\0'; r++)
		;
	for (d = 0; src[d] != '\0'; d++)
	{
		dest[r] = src[d];
		r++;
	}
	dest[r] = '\0';
	return (dest);
}


/**
 * *_strcpy - copies the string pointed to by src
 * @dest: type char pointer to the dest of the copied str
 * @src: type char pointer to the source of str
 * Return: the dest
 */

char *_strcpy(char *dest, char *src)
{
	size_t y;

	for (y = 0; src[y] != '\0'; y++)
	{
		dest[y] = src[y];
	}
	dest[y] = '\0';
	return (dest);
}


/**
 * _strcmp - function that compares two strings
 * @s1: type str compared
 * @s2: type str compared
 * Return: always 0
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++)
		;
	if (s1[a] > s2[a])
		return (1);
	if (s1[a] < s2[a])
		return (-1);
	return (0);
}


/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: character
 * Return: the pointer to the first occurrence of the character c
 */

char *_strchr(char *s, char c)
{
	unsigned int d = 0;

	for (d = 0; *(s + d) != '\0'; d++)
		if (*(s + d) == c)
			return (s + d);
	if (*(s + d) == c)
		return (s + d);
	return ('\0');
}


/**
 * _strspn - gets the ength of a prefix substring
 * @s: initial segment
 * @accept: accepted bytes
 * Return: the number of accepted bytes
 */

int _strspn(char *s, char *accept)
{
	int d, y, rose;

	for (d = 0; *(s + d) != '\0'; d++)
	{
		rose = 1;
		for (y = 0; *(accept + y) != '\0'; y++)
		{
			if (*(s + d) == *(accept + y))
			{
				rose = 0;
				break;
			}
		}
		if (rose == 1)
			break;
	}
	return (d);
}
