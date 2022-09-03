include "main.h"

/**
 * rev_string - reverses a string
 * @s: input string
 * Return: no return
 */

void rev_string(char *s)
{
	int count = 0, rd, ro;
	char *str, tmp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;
	for (rd = 0; rd < (count - 1); rd++)
	{
		for (ro = rd + 1; ro > 0; ro--)
		{
			tmp = *(str + ro);
			*(str + ro) = *(str + (ro - 1));
			*(str + (ro - 1)) = tmp;
		}
	}
}
