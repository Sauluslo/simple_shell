#include <stdio.h>
#include "shell.h"
/**
 * _strcpy - Write a function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: Array
 * @src: Array
 *
 * Return: dest.
*/
char *_strcpy(char *dest, char *src)
{
	int i, n;

	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	dest[n] = '\0';
	return (dest);
}
