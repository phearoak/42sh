/*
** EPITECH PROJECT, 2021
** Minishell
** File description:
** split sh command
*/

#include <my.h>
#include <minishell.h>
#include <string.h>

int check_if_command(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    if (c == '|' || c == '<' || c == '>' || c == ';' || c == '&')
        return (-1);
    return (0);
}

int count_sh_command(char *str)
{
    int size = 0;
    int command = 2;

    while (*str) {
        if (command == 0 && check_if_command(*str) == 1) {
            jump_space_in_str(&str);
            command = 2;
        }
        if (command != 1 && check_if_command(*str) == 0) {
            jump_command_in_str(&str);
            size++;
            command = 1;
        }
        if (command != 0 && check_if_command(*str) == -1) {
            jump_separator_in_str(&str);
            size++;
            command = 0;
        }
    }
    return (size);
}

char *get_sh_command(char **start_str)
{
    char *str = *start_str;
    int index = 0;
    int command = 0;

    while ((*start_str)[0] == ' ' || (*start_str)[0] == '\t')
        *start_str = *start_str + 1;
    str = *start_str;
    if (str[index] == '\0')
        return (dup_min_max(str, 0, 0));
    if (check_if_command(str[index]) == -1)
        command = -1;
    for (; str[index] != '\n' && str[index] != '\0'; index++) {
        if ((command == -1 && check_if_command(str[index]) != -1) || \
        (command == 0 && check_if_command(str[index]) == -1))
            break;
        jump_special_char_in_command(str, &index, command);
    }
    *start_str = *start_str + index;
    return (dup_min_max(str, 0, index));
}

int check_parents(char *str)
{
    int parent = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(')
            parent++;
        if (str[i] == ')')
            parent--;
        if (parent < 0) {
            my_putstr_error("Too many )'s.\n");
            return (-1);
        }
    }
    if (parent > 0) {
        my_putstr_error("Too many ('s.\n");
        return (-1);
    }
    return (0);
}

char **split_sh_command(char *str)
{
    int size = 0;
    char **array = NULL;

    jump_space_in_str(&str);
    if (check_parents(str) == -1)
        return (NULL);
    size = count_sh_command(str);
    array = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++) {
        array[i] = get_sh_command(&str);
    }
    array[size] = NULL;
    array = check_add_str_for_redirection(array);
    return (array);
}