#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _puts - prints a string of characters
* @str: string pointer
*
* Return: void
*/

void _puts(char *str)
{
while (*str != '\0')
{
	_putchar(*str);
	str++;
}
_putchar('\n');

return;
}

void main(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
	return;
}
