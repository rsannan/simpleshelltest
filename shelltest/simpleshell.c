#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARG 20
void get_cmd();
void convert_cmd();

char *argv[MAX_ARG];
char *cmd = NULL;

/**
* main - super simple shell
*
* Return: 0 otherwise -1
*/
int main()
{
	pid_t my_pid, child_pid;
	int status;
	
	while (1)
	{
		get_cmd();
		convert_cmd();
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}
}

/**
* get_cmd - gets user command
*
* Return: void
*/
void get_cmd()
{
	size_t bufsize = 0;
	const char c = '$';
	size_t strsize;
	write(1, &c, 1);
	/*store user cmd in buffer and use strsize to get length of cmd*/
	strsize = getline(&cmd, &bufsize, stdin);
	/*remember to free the buffer buddy*/
	/*shifting the null terminator up to remove \n*/
	if((strsize > 0) && (cmd[strsize - 1] == '\n'))
		cmd[strsize - 1] = '\0';
}

/**
* convert_cmd - splits the arguments and adds them to argv array
* 
* Return: Void
*/
void convert_cmd()
{
	int i = 0;
	char *s;
	s = strtok(cmd, " ");
	while (s != NULL)
	{
		argv[i] = s;
		i++;
		s = strtok(NULL, " ");
	}
}
