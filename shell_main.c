#include "shell.h"

/**
 * main - Main simple shell function
 * @arguc: arguements count
 * @argu: arguements
 *
 * Return: 0 Success
 */

int main(int arguc, char **argu)
{
	(void) argu;
	char *l = NULL;
	char **com = NULL;
	(void) arguc;
	int stat;

	for (;;)
	{
		l = readl();
		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		com = tokenizer(l);
		if (!com)
			continue;

		stat = _execute(com, argu);
	}
}
