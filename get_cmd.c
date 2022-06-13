#include "main.h"
/**
* get_cmd - gets user command and stores it in cmd
*
* Return: void
*/
void get_cmd()
{
	int line_err, write_err;
	write_err = write(1, "$", 1);
	if (write_err == -1)
		perror("./hsh: ");

	line_err = getline(&cmd, $bufsize, stdin);



	return;
}
