#include "shell.h"









char *tok = '\0', *tmp = '\0';
int cpt = 0, i = 0;
char **com = '\0';

if (!l)
	return('\0');

tmp = _strdup(line);
tok = strtok(tmp, DELIM);


while (tok)
{
	cpt++;
	tok = strtok('\0', DELIM);
}
free(tmp), tmp = '\0';

com = malloc(sizeof(char *) *(cpt + 1));
if (!com)
{
	free(line), line = '\0';
return ('\0');
}
tok = strtok(l, DELIM);
while (tok)
{
	com[i] = _strdup(tok);
	tok = strtok('\0', DELIM);
	n++;
}
free(l), l = '\0';
com[i] = '\0';
return (command);
}
