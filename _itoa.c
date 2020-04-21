#include "shell.h"
/**
 * _itoa - change integer to string
 * @num: integer
 * @str: is a string
 * @base: is base 10
 *
 * Return: always successful integer convert to string.
*/
char *_itoa(int num, char *str, int base)
{
	int i = 0;
	bool isNegative = false;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}
/**
 * reverse - A utility function to reverse a string
 * @str: string.
 * @length: len of the string
 *
 * Return: Always successful string.
*/
char *reverse(char *str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		swap(&str[start], &str[end]);
		start++;
		end--;
	}
	return (str);
}
/**
 * swap - change the value and realice temp
 * @xp: value 1
 * @yp: value 2
 *
 * Return: Always successful.
*/
void swap(char *xp, char *yp)
{
	int temp = *xp;

	*xp = *yp;
	*yp = temp;
}
