#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(void)
{
char *cmd = NULL;
size_t bufsize = 0;

getline(&cmd, &bufsize, stdin);

if(isatty(STDIN_FILENO))
{
	printf("THIS is TRue\n");
	printf("%s\n", cmd);
}
else
{
	printf("This is false\n");
	printf("%s\n", cmd);
}


    /* carry on... */
    return 0;
}
