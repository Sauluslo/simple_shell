#include "shell.h"
/**
 * concat_command - concatena el path con el comando ingresado
 * @path: pathname
 * @command: comando ingresado.
 *
 * Return: Always successful
*/
char *concat_command(char *path, char *command)
{
	char *buffer = NULL;
	char *path_slash = _strcat(path, "/", buffer);
	char *fullpath_command = _strcat(path_slash, command, buffer);
	free(path_slash);
	return (fullpath_command);
}
