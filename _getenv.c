#include "shell.h"

char *_getenv(char *key)
{
    int i = 1;
	char *word;
	char *line = *environ;

	for (; line; i++)
	{
        char *line_copy = malloc((_strlen(line) + 1) * sizeof(char));
	    _strcpy(line_copy, line);
	    word = strtok(line_copy, "=");
        if (word != NULL)
        {
            if (_strcmp(word, key) == 0)
            {
                free(line_copy);
                break;
            }
        }

		line = *(environ + i);
        free(line_copy);
	}

    return (_getvalue(line, key));
}

char *_getvalue(char *keyvalue, char *key)
{
	int i, j = 0;
	int keylen = _strlen(key) + 1;
	int len = _strlen(keyvalue);
	char *buffer = malloc((len - keylen + 1) * sizeof(char));

	for (i = keylen; i < len; i++)
	{
		buffer[j++] = keyvalue[i];
	}
	buffer[j] = '\0';

	return (buffer);
}
