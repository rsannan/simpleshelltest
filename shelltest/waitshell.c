#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
/**
* main - executes a ls-l in 5 sub processes
*
*Return: void
*/

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int status, count;
	pid_t my_pid, child_pid;

	for (count = 0; count < 5; count++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		my_pid = getpid();
		
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			printf("%u\n", my_pid);
			printf("%u\n", child_pid);
		}
		else
		{
			wait(&status);
			printf("%u\n", my_pid);
			printf("%u\n", child_pid);
			/*if (WIFSIGNALED(status))
			{
				continue;
			}*/
		}

	}
	return (0);
}
