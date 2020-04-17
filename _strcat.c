#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @str1: String of path.
 * @str2: String of command.
 * @res: Resulto of concatenate path and command.
 * Return: concatenated strings
 */
char *_strcat(char *str1, char *str2, char *res)
{
	int str1l, str2l, j, i = 0;

	str1l = _strlen(str1);
	str2l = _strlen(str2);
	res = malloc(str1l + str2l + 2 * sizeof(char));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		res[i] = str2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
