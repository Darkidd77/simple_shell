#include "shell.h"

/**
 * inp_ibuf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @leng: address of len var
 *
 * Return: bytes read
 */
ssize_t inp_ibuf(info_t *info, char **buf, size_t *leng)
{
	ssize_t n = 0;
	size_t leng_p = 0;

	if (!*leng) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		n = getline(buf, &leng_p, stdin);
#else
		n = _getline(info, buf, &leng_p);
#endif
		if (n > 0)
		{
			if ((*buf)[n - 1] == '\n')
			{
				(*buf)[n - 1] = '\0'; /* remove trailing newline */
				n--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*leng = n;
				info->cmd_buf = buf;
			}
		}
	}
	return (n);
}

/**
 * get_inp - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_inp(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t x, y, leng;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &leng);
	if (r == -1) /* EOF */
		return (-1);
	if (leng)	/* we have commands left in the chain buffer */
	{
		y = x; /* init new iterator to current buf position */
		p = buf + x; /* get pointer for return */

		check_chain(info, buf, &y, x, leng);
		while (y < leng) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &y))
				break;
			y++;
		}

		x = y + 1; /* increment past nulled ';'' */
		if (x >= leng) /* reached end of buffer? */
		{
			x = leng = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * red_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @z: size
 *
 * Return: r
 */
ssize_t red_buf(info_t *info, char *buf, size_t *z)
{
	ssize_t r = 0;

	if (*z)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*z = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @p: address of pointer to buffer, preallocated or NULL
 * @leng: size of preallocated ptr buffer if not NULL
 *
 * Return: a
 */
int _getline(info_t *info, char **p, size_t *leng)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, a = 0;
	char *pr = NULL, *new_p = NULL, *c;

	pr = *p;
	if (pr && length)
		a = *leng;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(pr, a, a ? a + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (pr ? free(pr), -1 : -1);

	if (a)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	a += k - i;
	i = k;
	pr = new_p;

	if (leng)
		*leng = a;
	*p = pr;
	return (a);
}

/**
 * sigintHand - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHand(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
