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

#define MAX_ARG 20
char *argv[MAX_ARG];
char *cmd;
size_t bufsize;
char *PATH[] = {"/usr/bin/", "/usr/sbin/",
"/usr/local/bin/", "/usr/local/sbin/",
"/bin/", "/sbin", "NULL"};

#endif
