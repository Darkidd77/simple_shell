#include "shell.h"

char **tok(char *l)
{
	char *tok = NULL, *tmp = NULL;
	int cpt = 0, i = 0;
	char **com = NULL;
	
	if (!l)
	return(NULL);
	
	tmp = _strdup(l);
	tok = strtok(tmp, DELIM);
	
	while (tok)
	{
		
		cpt++;
		tok = strtok(NULL, DELIM);
	}
	
	free(tmp), tmp = NULL;
	
	com = malloc(sizeof(char *) *(cpt + 1));
	if (!com)
	{
		free(l), l = NULL;
		return (NULL);
	}
	
	tok = strtok(l, DELIM);
	while (tok)
	{
		com[i] = _strdup(tok);
		tok = strtok(NULL, DELIM);
		i++;
	}
	free(l), l = NULL;
	com[i] = NULL;
	return (com);
}
