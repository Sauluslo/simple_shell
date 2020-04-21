#include "shell.h"
/**
 * error_msg - msg of error 127, not found
 * @count: var type integer, count of error.
 * @argv: arguments
 * @shell_name: command add for the user
 *
 * Return: Always successfull 127.
*/
int error_msg(int count, char **argv, char *shell_name)
{
	char *buf1 = NULL;
	char *buf2 = NULL;
	char *buf3 = NULL;
	char *buf4 = NULL;
	char *buf5 = NULL;
	char *bufitoa = malloc(100 * sizeof(char));
	char *str1 = _strcat(shell_name, ": ", buf1);
	char *str2 = _strcat(str1, _itoa(count, bufitoa, 10), buf2);
	char *str3 = _strcat(str2, ": ", buf3);
	char *str4 = _strcat(str3, argv[0], buf4);
	char *errormsg = _strcat(str4, ": not found\n", buf5);

	write_error(errormsg);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(bufitoa);
	free(errormsg);
	return (127);
}
