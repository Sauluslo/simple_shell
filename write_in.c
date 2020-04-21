#include "shell.h"
/**
 * write_in - print in stdin.
 * @s: msg in out.
 *
 * Return: Always successful
*/
void write_in(char *s)
{
	int len = _strlen(s);

	write(STDIN_FILENO, s, len);
}
