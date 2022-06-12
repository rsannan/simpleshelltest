#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define MAX_ARG 20
void get_cmd();
void convert_cmd();

char *argv[MAX_ARG];
int status;
int mode = 0;
char *cmd = NULL;
char *PATH[] = {"/usr/bin/", "/usr/sbin/",
"/usr/local/bin/", "/usr/local/sbin/",
"/bin/", "/sbin", "NULL"};

/**
* main - super simple shell
*
* Return: 0 otherwise -1
*/
int main()
{
	pid_t my_pid, child_pid, p_pid;
	struct stat st, idle_st;
	
	while (mode != 1)
	{
		get_cmd();
		if (isatty(STDIN_FILENO))
			mode = 0;
		else
			mode = 1;

		convert_cmd();
		if (stat(argv[0], &st) != 0)
		{
			int ind = 0;
			while (PATH[ind] != "NULL")
			{
				char fullpath[MAX_ARG];
				/*ADD STRCAT FUNC of your own*/
				strcat(fullpath, PATH[ind]);
				strcat(fullpath, argv[0]);
				if (stat(fullpath, &st) == 0)
				{
					argv[0] = fullpath;
					break;
				}
				/*ADD MEMSET function of your own*/
				memset(fullpath, '\0', sizeof fullpath);
				ind++;
			}
		}
		child_pid = fork();
		my_pid = getpid();

		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
		
	}
	exit(98);
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
