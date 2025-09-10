// myshell.h
// Header file for simple shell implementation
// Declares core shell functions and constants

#ifndef MYSHELL_H
#define MYSHELL_H

#define ONGOING_SESSION 1
#define CHAR_LIM 100
#define ARG_LIM  100

void welcome();
void prompt();
void input(char command[]);
void parse(char command[], char *tokens[]);
void execute(char *tokens[]);
void goodbye();

#endif