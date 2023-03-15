/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** echo command
*/

#include <minishell.h>
#include <my.h>

int check_flag2(char *str, char flag)
{
    for (int j = 0; str[j]; j++)
        if (str[j] == flag)
            return (1);
    return (0);
}

int check_flag(char **argv, char flag)
{
    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '-' && check_flag2(argv[i], flag) == 1)
            return (1);
    }
    return (0);
}

char *check_sentence(char *str)
{
    if ((str[0] == '"' && str[my_strlen(str) - 1] == '"') ||
    (str[0] == 39 && str[my_strlen(str) - 1] == 39)) {
        str = str + 1;
        str[my_strlen(str) - 1] = '\0';
    }
    return (str);
}

int do_command_echo(char **argv)
{
    int n_f = 0;
    int i = 1;
    int len = 0;

    for (; argv[len]; len++);
    if (len > 1 && my_strcmp("-n", argv[1]) == 0) {
        n_f = 1;
        i = 2;
    }
    for (; argv[i]; i++) {
        argv[i] = check_sentence(argv[i]);
        if (i > 1 + n_f)
            my_putchar(' ');
        my_putstr(argv[i]);
    }
    if (n_f == 0)
        my_putchar('\n');
    return (0);
}