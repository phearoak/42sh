/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** get variables
*/

#include <minishell.h>
#include <my.h>

int check_is_variable(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '$')
            return (1);
    return (0);
}

int make_str_var(char **str, char *val, char *pre_var, char *post_var)
{
    if (val == NULL)
        return (1);
    (*str) = my_strncat_dup(pre_var, val, my_strlen(val));
    (*str) = my_strncat_dup(*str, post_var, my_strlen(post_var));
    return (0);
}

int check_variable(char **str, shell_t *shell)
{
    char *pre_var = "";
    char *post_var = "";
    int index = 0;
    char *tmp = NULL;

    if (check_is_variable(*str) == 0)
        return (0);
    for (; (*str)[index] && (*str)[index] != '$'; index++)
        pre_var = my_strncat_dup(pre_var, &(*str)[index], 1);
    tmp = my_strdup((*str) + index + 1);
    if (tmp[0] == '{') {
        for (index = 1; tmp[index] != '}'; index++);
        tmp[index] = 0;
        tmp++;
        post_var = tmp + index;
    }
    return (make_str_var(str, variable_value(shell, tmp), pre_var, post_var));
}

char **get_variables(char **argv, shell_t *shell)
{
    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '"' && argv[i][strlen(argv[i]) - 1] == '"') {
            argv[i] += 1;
            argv[i][strlen(argv[i]) - 1] = '\0';
        }
    }
    for (int i = 0; argv[i]; i++)
        if (check_variable(&argv[i], shell) == 1)
            return (NULL);
    return (argv);
}