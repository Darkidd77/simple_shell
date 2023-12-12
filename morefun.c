#include "shell.h"

void freearrayofstring(char **ar)
{
	int n;
	
	if (!ar)
		return;

	for (n = 0; ar[i]; n++)
	{
		free(ar[n]);
		ar[n] = '\0';
	}

	free(ar), ar = '\0';
}

void printerror(char *name, char *cmd, int idx)
{
	char *index;


	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
}
