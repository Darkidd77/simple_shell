#include "shell.h"

char *_getpath( char *com)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; com[i]; i++)
	{
		if (com[i] == '/')
		{
			if (stat(com, &st) == 0)
				return (_strdup(com));

			return (NULL);
		}
	}

	path_env = _getenv("PATH");

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(com));
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, com);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}

			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}

int main(int ac, char **av)
{
	char *full_cmd;

	full_cmd = _getpath(av[1]);
	if (full_cmd)
		printf("%s\n", full_cmd);
	else
		printf("does not exist\n");
}

