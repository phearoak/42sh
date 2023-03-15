/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** jump quote in str
*/

#include <minishell.h>

void jump_quote_with_index(char *str, int *index)
{
    *index = *index + 1;
    while (str[*index] && str[*index] != '`')
        *index = *index + 1;
    if (str[*index] == '\0')
        *index = *index - 1;
}

void jump_quote_in_str(char **str)
{
    while (**str && **str != '`')
        *str = *str + 1;
    *str = *str + 1;
}

void jump_special_char_in_command(char *str, int *index, int command)
{
    if (command == 0 && str[*index] == '(')
        jump_parent_with_index(str, index);
    if (command == 0 && str[*index] == '`')
        jump_quote_with_index(str, index);
}