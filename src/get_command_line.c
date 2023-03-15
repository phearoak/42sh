/*
** EPITECH PROJECT, 2021
** get command line
** File description:
** get command line
*/

#include <minishell.h>
#include <my.h>

int is_separator(char c)
{
    if (c == '\t' || c == ' ' || c == '\n')
        return (1);
    return (0);
}

int strlen_command(char *str, int i)
{
    int counter = 0;
    int quote = 0;

    while ((is_separator(str[i]) != 1 && str[i] != '\0') || \
    (i != 0 && str[i - 1] == '\\') || (quote == 1  && str[i] != '\0')) {
        if (str[i] == '`')
            quote = quote == 0 ? 1 : 0;
        i++;
        counter++;
    }
    return (counter);
}

char *get_command_line(char *str)
{
    int i = 0;
    int j = 0;
    char *command = NULL;
    int quote = 0;

    while (is_separator(str[i]) == 1)
        i++;
    if (str[i] == '\0')
        return (NULL);
    command = malloc(strlen_command(str, i) + 1);
    for (; (is_separator(str[i]) != 1 && str[i] != '\0') || \
    (i != 0 && str[i - 1] == '\\') || (quote == 1  && str[i] != '\0'); j++) {
        if (str[i] == '`')
            quote = quote == 0 ? 1 : 0;
        command[j] = str[i];
        i++;
    }
    command[j] = 0;
    return (command);
}