#include "shell.h"
/**
 * _strlen - check the code for Holberton School students.
 * @s: Pointer s.
 *
 * Return: Always 0.
*/
int _strlen(char *s)
{
	int v;
	char *str = s;

	for (v = 0; str[v] != '\0'; v++)
	{
		;
	}
	return (v);
}
