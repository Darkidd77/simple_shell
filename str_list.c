#include "shell.h"

/**
 * add_nd - adds a node to the start of the list
 * @hed: address of pointer to head node
 * @str: str field of node
 * @n: node index used by history
 *
 * Return: size of list
 */
list_t *add_nd(list_t **hed, const char *str, int n)
{
	list_t *new_hed;

	if (!hed)
		return (NULL);
	new_hed = malloc(sizeof(list_t));
	if (!new_hed)
		return (NULL);
	_memset((void *)new_hed, 0, sizeof(list_t));
	new_hed->n = n;
	if (str)
	{
		new_hed->str = _strdup(str);
		if (!new_hed->str)
		{
			free(new_hed);
			return (NULL);
		}
	}
	new_hed->next = *hed;
	*hed = new_hed;
	return (new_hed);
}

/**
 * add_nd_end - adds a node to the end of the list
 * @hed: address of pointer to head node
 * @str: str field of node
 * @n: node index used by history
 *
 * Return: size of list
 */
list_t *add_nd_end(list_t **hed, const char *str, int n)
{
	list_t *new_nd, *nd;

	if (!hed)
		return (NULL);

	nd = *hed;
	new_nd = malloc(sizeof(list_t));
	if (!new_nd)
		return (NULL);
	_memset((void *)new_nd, 0, sizeof(list_t));
	new_nd->n = n;
	if (str)
	{
		new_nd->str = _strdup(str);
		if (!new_nd->str)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = new_nd;
	}
	else
		*hed = new_nd;
	return (new_nd);
}

/**
 * print_liststr - prints only the str element of a list_t linked list
 * @pnd: pointer to first node
 *
 * Return: size of list
 */
size_t print_liststr(const list_t *pnd)
{
	size_t n = 0;

	while (pnd)
	{
		_puts(pnd->str ? pnd->str : "(nil)");
		_puts("\n");
		pnd = pnd->next;
		n++;
	}
	return (n);
}

/**
 * del_nd_index - deletes node at given index
 * @hed: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int del_nd_index(list_t **hed, unsigned int index)
{
	list_t *nd, *prev_nd;
	unsigned int n = 0;

	if (!hed || !*hed)
		return (0);

	if (!index)
	{
		nd = *hed;
		*hed = (*hed)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	nd = *hed;
	while (nd)
	{
		if (n == index)
		{
			prev_nd->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		n++;
		prev_nd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * f_list - frees all nodes of a list
 * @hed_ptr: address of pointer to head node
 *
 * Return: void
 */
void f_list(list_t **hed_ptr)
{
	list_t *nd, *next_nd, *hed;

	if (!hed_ptr || !*hed_ptr)
		return;
	hed = *hed_ptr;
	nd = hed;
	while (nd)
	{
		next_nd = nd->next;
		free(nd->str);
		free(nd);
		nd = next_nd;
	}
	*hed_ptr = NULL;
}
