#include "shell.h"

/**
 * list_leng - determines length of linked list
 * @pnd: pointer to first node
 *
 * Return: size of list
 */
size_t list_leng(const list_t *pnd)
{
	size_t n = 0;

	while (pnd)
	{
		pnd = pnd->next;
		n++;
	}
	return (n);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_str(list_t *hed)
{
	list_t *nd = hed;
	size_t i = list_leng(hed), j;
	char **strs;
	char *str;

	if (!hed || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; nd; nd = nd->next, i++)
	{
		str = malloc(_strleng(nd->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcopy(str, nd->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * p_list - prints all elements of a list_t linked list
 * @pnd: pointer to first node
 *
 * Return: size of list
 */
size_t p_list(const list_t *pnd)
{
	size_t n = 0;

	while (pnd)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(pnd->str ? pnd->str : "(nil)");
		_puts("\n");
		pnd = pnd->next;
		n++;
	}
	return (n);
}

/**
 * node_starts_w - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_w(list_t *nd, char *prfix, char ch)
{
	char *p = NULL;

	while (nd)
	{
		p = starts_w(nd->str, prfix);
		if (p && ((ch == -1) || (*p == ch)))
			return (nd);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * get_nd_index - gets the index of a node
 * @hed: pointer to list head
 * @nd: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_nd_index(list_t *hed, list_t *nd)
{
	size_t n = 0;

	while (hed)
	{
		if (hed == nd)
			return (n);
		hed = hed->next;
		n++;
	}
	return (-1);
}
