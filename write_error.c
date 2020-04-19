#include "shell.h"
/**
 * write_error - print in stderr
 * @s: msg error
 *
 * Return: Always successful
*/
void write_error(char *s)
{
	int len = _strlen(s);

	write(STDERR_FILENO, s, len);
}
