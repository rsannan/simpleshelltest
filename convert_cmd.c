#include "main.h"
/**
* convert_cmd - transfers string cmd to argv array
*
* Return: void
*/

void convert_cmd()
{
	int i = 0;
	char *s;

	s = strtok(cmd, " ");
	while (s != NULL)
	{
		argv[i] = s;
		s = strtok(NULL, " ");
		i++;
	}
}
