#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(void)
{
	int child;
	int waitid;
	int line = 1;
	size_t n = 0;
	char *str;
	char *newprog[3];

	write(1,"$",1);
	line = getline(&str, &n , stdin);
	str = strtok(str, "\n");
	newprog[0] = str;
	newprog[1] = NULL;
	newprog[3] = NULL;
	while (line != -1 )
	{
		child = fork();
		if (child == 0)
			execve(newprog[0], newprog, NULL);
		else
			wait(&waitid);
		write(1, "$", 1);
		n = 0;
		line = getline(&str, &n, stdin);
		str = strtok(str, "\n");
	}
	exit(98);
}
