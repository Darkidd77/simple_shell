#include "shell.h"

/**
 * pofree - frees a pointer and NULLs the address
 * @p: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int pofree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}

#include "shell.h"

/**
 **_memoset - fills memory with a constant byte
 *@a: the pointer to the memory area
 *@f: the byte to fill *s with
 *@i: the amount of bytes to be filled
 *Return: (a) a pointer to the memory area s
 */
char *_memoset(char *a, char f, unsigned int i)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		a[x] = f;
	return (a);
}

/**
 * ssfree - frees a string of strings
 * @ss: string of strings
 */
void ssfree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _rlloc - reallocates a block of memory
 * @p: pointer to previous malloc'ated block
 * @olds: byte size of previous block
 * @news: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_rlloc(void *p, unsigned int olds, unsigned int news)
{
	char *q;

	if (!p)
		return (malloc(news));
	if (!news)
		return (free(p), NULL);
	if (news == olds)
		return (p);

	q = malloc(news);
	if (!q)
		return (NULL);

	olds = olds < news ? olds : news;
	while (olds--)
		q[olds] = ((char *)p)[olds];
	free(p);
	return (q);
}
