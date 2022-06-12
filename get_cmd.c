#include "main.h"
/**
* get_cmd - gets user command and stores it in cmd
*
* Return: void
*/
int get_cmd()
{
	int line = 1;
	write(1, "$", 1);
	line = getline(&cmd, $bufsize, stdin);

	return (line);
}
