#include "shell.h"

/**
 * get_envi - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_envi(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenvi - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @svar: the string env var property
 */
int _unsetenvi(info_t *info, char *svar)
{
	list_t *nd = info->env;
	size_t i = 0;
	char *p;

	if (!nd || !svar)
		return (0);

	while (nd)
	{
		p = starts_with(nd->str, svar);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			nd = info->env;
			continue;
		}
		nd = nd->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenvi(info_t *info, char *svar, char *val)
{
	char *buf = NULL;
	list_t *nd;
	char *p;

	if (!svar || !val)
		return (0);

	buf = malloc(_strleng(svar) + _strleng(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, svar);
	_strcat(buf, "=");
	_strcat(buf, val);
	nd = info->env;
	while (nd)
	{
		p = starts_w(nd->str, svar);
		if (p && *p == '=')
		{
			free(nd->str);
			nd->str = buf;
			info->env_changed = 1;
			return (0);
		}
		nd = nd->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
