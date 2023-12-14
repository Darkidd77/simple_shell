#include "shell.h"


/**
 * _execu - function to execute the proccess
 *
 * @com: command line
 * @arguv: arguments
 *
 * Return: stat
 */

int _execu(char **com, char **arguv)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == 0)
	{
		if (execve(com[0], com, environ) == -1)
		{
			perror(arguv[0]);
			freearray2D(com);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray2D(com);
	}
	return (WEXITSTATUS(stat));
}
