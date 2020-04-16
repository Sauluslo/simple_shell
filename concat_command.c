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

	return (_strcat(path, command, buffer));
}
