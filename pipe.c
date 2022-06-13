#include "main.h"
/**
* cmd_mode - checks if interactive shell or not
*
* Return: Void
*/
void cmd_mode(void)
{
	if (isatty(STDIN_FILENO))
		mode = 0;
	else
		mode = 1;
	return;
}
