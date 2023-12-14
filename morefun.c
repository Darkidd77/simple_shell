#include "shell.h"

/**
 * interact - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * if_delim - checks if character is a delimeter
 * @ch: the char to check
 * @deli: the delimeter string
 * Return: 1 if true, 0 if false
 */
int if_delim(char ch, char *deli)
{
	while (*deli)
		if (*deli++ == ch)
			return (1);
	return (0);
}

/**
 *_ifalpha - checks for alphabetic character
 *@ch: The character to input
 *Return: 1 if ch is alphabetic, 0 otherwise
 */

int _ifalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int n, sign = 1, flag = 0, outp;
	unsigned int rslt = 0;

	for (n = 0;  str[n] != '\0' && flag != 2; n++)
	{
		if (str[n] == '-')
			sign *= -1;

		if (str[n] >= '0' && str[n] <= '9')
		{
			flag = 1;
			rslt *= 10;
			rslt += (str[n] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		outp = -rslt;
	else
		outp = rslt;

	return (outp);
}
