#include <stdio.h>
#include <stdlib.h>

int input(char *s,int length);

int main()
{
    char *buffer = NULL;
    size_t bufsize = 0;
    size_t characters;

    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);
    if ((characters > 0) && (buffer[characters - 1] == '\n'))
        	buffer[characters - 1] = '\0';
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);

    return(0);
}
