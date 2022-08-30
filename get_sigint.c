include "main.h"

/**
 * git_sigint - Handle the ctrl + ccall in prompt
 * @sig: signal handler
 * Return: always 0
 */

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^", 5);
}
