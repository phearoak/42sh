/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** jump in str
*/

#include <minishell.h>

void jump_space_in_str(char **str)
{
    while (**str && (**str == '\t' || **str == ' ')) {
        *str = *str + 1;
    }
}

void jump_parent_in_str(char **str)
{
    while (**str && **str != ')')
        *str = *str + 1;
    *str = *str + 1;
}

void jump_command_in_str(char **str)
{
    while (**str && check_if_command(**str) != -1) {
        if (**str == '(') {
            *str = *str + 1;
            jump_parent_in_str(str);
            continue;
        }
        if (**str == '`') {
            *str = *str + 1;
            jump_quote_in_str(str);
            continue;
        }
        *str = *str + 1;
    }
}

void jump_separator_in_str(char **str)
{
    while (**str && check_if_command(**str) == -1) {
        *str = *str + 1;
    }
}

void jump_parent_with_index(char *str, int *index)
{
    while (str[*index] && str[*index] != ')')
        *index = *index + 1;
    if (str[*index] == '\0')
        *index = *index - 1;
}