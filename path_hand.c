#include "shell.h"

/**
 * if_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int if_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dp_char - duplicates characters
 * @pstr: the PATH string
 * @star: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dp_char(char *pstr, int star, int stop)
{
	static char buf[1024];
	int x = 0, v = 0;

	for (v = 0, x = star; x < stop; x++)
		if (pstr[x] != ':')
			buf[v++] = pstr[x];
	buf[v] = 0;
	return (buf);
}

/**
 * fpath - finds this cmd in the PATH string
 * @info: the info struct
 * @pstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *fpath(info_t *info, char *pstr, char *cmd)
{
	int x = 0, crnt_pos = 0;
	char *p;

	if (!pstr)
		return (NULL);
	if ((_strleng(cmd) > 2) && starts_w(cmd, "./"))
	{
		if (if_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pstr[x] || pstr[x] == ':')
		{
			p = dp_char(pstr, crnt_pos, x);
			if (!*p)
				_strcat(p, cmd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cmd);
			}
			if (if_cmd(info, p))
				return (p);
			if (!pstr[x])
				break;
			crnt_pos = x;
		}
		x++;
	}
	return (NULL);
}
