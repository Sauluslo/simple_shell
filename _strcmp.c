#include "shell.h"
/**
 * _strcmp - Compares pointers to two strings.
 * @str1: A pointer to the first string to be compared.
 * @str2: A pointer to the second string to be compared.
 *
 * Return: If str1 < str2, the negative difference
 * of the first unmatched characters.
 * If str1 == str2, 0.
 * If str1 > str2, the positive difference of the first unmatched characters.
*/
int _strcmp(char *str1, char *str2)
{
	char *s1 = str1;
	char *s2 = str2;

	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
