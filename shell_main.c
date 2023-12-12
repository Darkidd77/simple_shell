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
	char *l = '\0';
	char **com = '\0';
	(void) ac;
	int stat;

	for (;;)
	{
		l = read_line();
		if (line == '\0')
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		com = tokenizer(l);
		if (!command)
			continue;

		stat = _execute(com, arguv);
	}
}
