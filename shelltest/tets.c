#include <stdio.h>
#include <unistd.h>
int _putchar(char c)
{
	return (write(2, &c, 1));
}
void print_number(int n)
{
unsigned int i = n;

if (n < 0)
{
	_putchar('-');
	i = -n;
}

if ((i / 10) > 0)
{
	print_number(i / 10);
}

_putchar((i % 10) + '0');

return;
}

void _putserr(char *str)
{
while (*str != '\0')
{
	_putchar(*str);
	str++;
}
return;
}

void main(void)
{
	char s[] = "cowb";
	char a[2] = "aa";
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%c\n", a[i]);
	}
	
	_putserr(s);
	_putserr(": ");
	print_number(__LINE__);
	_putserr(": ");
	perror(NULL);
	_putchar('\n');
}
