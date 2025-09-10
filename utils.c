// utils.c
// Utility file for simple shell implementation
// Defines core shell functions

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "myshell.h"
#include <sys/wait.h>

// Welcome!
void welcome()
{
    printf("\n               :: WELCOME TO LISH ::\n");
    printf("          :: THE LITTLE SHELL INTERFACE ::\n");
    printf(" \033[1;36m____           ____     _______      ____     ____\n");
    printf("|_  _|         |_  _|   /  _____|    |_  _|   |_  _|\n");
    printf(" |  |   __      |  |    \\_____  \\     |  | ___ |  |\n");
    printf(" |  |__|  |     |  |     _____) /     |  | ___ |  |\n");
    printf("|_________|    |____|    \\_____/     |____|   |____|\033[0m\n\n");
    printf("               :: LISH INITIALIZED ::\n");
    printf("                 :: SYSTEM READY ::\n\n");
}

// Display current working directory and prompt user
void prompt()
{
    const size_t size = 1024;
    char buffer[size];

    if (getcwd(buffer,size) != NULL)
        printf("%s$ ",buffer);
}

// Read a line of input from user
void input(char command[])
{
    fgets(command,CHAR_LIM,stdin);
    command[strcspn(command,"\n")] = '\0';
}

// Tokenize input into arguments for execvp()
void parse(char command[], char *tokens[])
{
    char *token = strtok(command," ");
    int i = 0;

    while (token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL," ");
    }

    tokens[i] = NULL;
}

// Fork and execute non-built-in commands
void execute(char *tokens[])
{
    // Create a new child process
    int process = fork();

    if (process < 0)
    {
        fprintf(stderr,"fork failed");
        exit(1);
    }
    else if (process == 0)
    {
        // In child process: replace with specified program
        if (execvp(tokens[0],tokens) == -1)
        {
            perror("execvp failed");
            exit(1);
        }
    }
    else
    {
        // In parent process: wait for child to finish
        wait(NULL);
    }
}

// Goodbye!
void goodbye()
{
    printf("\n               :: LISH TERMINATED ::\n");
    printf("                   :: GOODBYE ::\n\n");
    printf("         :: (C) CHRISTIAN SORENSEN 2025 ::\n");
    printf("             :: LIPSCOMB UNIVERSITY ::\n");
    printf("             :: ALL RIGHTS RESERVED ::\n\n");
}
