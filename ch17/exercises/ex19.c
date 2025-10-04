/*
Write a function that, when given a string as its argument, searches the following array of structures for a matching command name, then calls the function associated with that name.

    struct {
        char *cmd_name;
        void (*cmd_pointer)(void);
    } file_cmd[] = 
     {
     {"new",           new_cmd},
     {"open",          open_cmd},
     {"close",         close_cmd},
     {"close all",     close_all_cmd},
     {"save",          save_cmd},
     {"save as",       save_as_cmd},
     {"save all",      save_all_cmd},
     {"print",         print_cmd},
     {"exit",          exit_cmd},
     }
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_cmd(void)
{
    printf("Running new_cmd");
}

void open_cmd(void)
{
    printf("Running open_cmd");
}

void close_cmd(void)
{
    printf("Running close_cmd");
}

void close_all_cmd(void)
{
    printf("Running close_all_cmd");
}

void save_cmd(void)
{
    printf("Running save_cmd");
}

void save_as_cmd(void)
{
    printf("Running save_as_cmd");
}

void save_all_cmd(void)
{
    printf("Running save_all_cmd");
}

void print_cmd(void)
{
    printf("Running print_cmd");
}

void exit_cmd(void)
{
    printf("Running exit_cmd");
    exit(EXIT_SUCCESS);
}

struct {
        char *cmd_name;
        void (*cmd_pointer)(void);
    } file_cmd[] = 
     {
     {"new",           new_cmd},
     {"open",          open_cmd},
     {"close",         close_cmd},
     {"close all",     close_all_cmd},
     {"save",          save_cmd},
     {"save as",       save_as_cmd},
     {"save all",      save_all_cmd},
     {"print",         print_cmd},
     {"exit",          exit_cmd},
     };

void run_command(char *str)
{
    // A very convoluted way of doing this
    for (int i = 0; i < sizeof(file_cmd) / sizeof(file_cmd[0]); i++) {
        if (strcmp(str, (&file_cmd[i])->cmd_name) == 0) {
            ((&file_cmd[i])->cmd_pointer)();
            return;
        }
    }
    printf("Command doesn't exist");
    return;
}

int main(void)  
{   
    char cmd[20];
    printf("Enter a command: ");
    fgets(cmd, sizeof(cmd), stdin);
     // remove the newline and replace with null char so strcmp works
    strtok(cmd, "\n");
    run_command(cmd);
    return 0;
}
