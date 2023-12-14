#include "shell.h"

/**
 * _eratoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _eratoi(char *str)
{
	int n = 0;
	unsigned long int rslt = 0;

	if (*str == '+')
		str++;
	for (n = 0;  str[n] != '\0'; n++)
	{
		if (str[n] >= '0' && str[n] <= '9')
		{
			rslt *= 10;
			rslt += (str[n] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * error_print - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void error_print(info_t *para, char *erstr)
{
	_eputs(para->fname);
	_eputs(": ");
	print_d(para->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(para->argv[0]);
	_eputs(": ");
	_eputs(erstr);
}

/**
 * print_dec - function prints a decimal (integer) number (base 10)
 * @inp: the input
 * @fdsc: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_dec(int inp, int fdsc)
{
	int (*__putchar)(char) = _putchar;
	int n, c = 0;
	unsigned int _abs_, crnt;

	if (fdsc == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		c++;
	}
	else
		_abs_ = inp;
	crnt = _abs_;
	for (n = 1000000000; n > 1; n /= 10)
	{
		if (_abs_ / n)
		{
			__putchar('0' + crnt / n);
			c++;
		}
		crnt %= n;
	}
	__putchar('0' + crnt);
	c++;

	return (c);
}

/**
 * nconv - converter function, a clone of itoa
 * @n: number
 * @b: base
 * @flag: argument flags
 *
 * Return: string
 */
char *uconv(long int n, int b, int flag)
{
	static char *ar;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long i = n;

	if (!(flag & CONVERT_UNSIGNED) && n < 0)
	{
		i = -n;
		sign = '-';

	}
	ar = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = ar[i % b];
		i /= b;
	} while (i != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void rm_comment(char *buff)
{
	int n;

	for (n = 0; buff[n] != '\0'; n++)
		if (buff[n] == '#' && (!n || buff[n - 1] == ' '))
		{
			buff[n] = '\0';
			break;
		}
}
