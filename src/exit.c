/*
** EPITECH PROJECT, 2021
** exit
** File description:
** exit
*/

#include <my.h>
#include <minishell.h>

void do_command_exit(int option)
{
    if (option == 1)
        my_putstr("exit\n");
    exit(0);
}

void check_command_exit(int check, int *exit, int separator, int type)
{
    if (check == 777 || (type == 0 && check != 0))
        *exit = 1;
    if (*exit == 1 && (separator == 6 || separator == -1))
        do_command_exit(type);
}