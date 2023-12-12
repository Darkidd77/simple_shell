#include "shell.h"



char *getenv(const char *name)
{



	int main()
	{
		int i;

		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}

		return (0);
	}

