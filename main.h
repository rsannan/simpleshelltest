#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_ARG 20

/**
* struct system_call - matches important system calls to functions
* @s: string call
* @f: function call
*
*/
typedef struct system_call
{
	char *s;
	void (*f)();
}sys_call;

extern char **environ;
char *argv[MAX_ARG];
char *cmd;
size_t bufsize;
int mode = 0;
char *PATH[] = {"/usr/bin/", "/usr/sbin/",
"/usr/local/bin/", "/usr/local/sbin/",
"/bin/", "/sbin", "NULL"};

#endif
