// myshell.c
// Main file for simple shell implementation
// Implements simple shell

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "myshell.h"

int main()
{
    welcome();
    
    while (ONGOING_SESSION)
    {
        // Raw input buffer
        char command[CHAR_LIM];

        // Parsed arguments array
        char *arguments[ARG_LIM];

        // Display prompt, read user input, split into arguments
        prompt();
        input(command);
        parse(command,arguments);

        // Check built-in command: exit
        if (strcmp(command,"exit") == 0)
        {
            goodbye();
            break;
        }

        // Check built-in command: cd
        if (strcmp(arguments[0], "cd") == 0)
        {
            if (arguments[1] == NULL)
                fprintf(stderr, "cd: missing argument\n");
            else if (chdir(arguments[1]) == -1)
                perror("chdir failed");
            continue;
        }

        // Execute all other commands
        execute(arguments);
    }
}