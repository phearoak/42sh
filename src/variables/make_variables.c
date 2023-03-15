/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** make variables
*/

#include <minishell.h>
#include <my.h>

int is_equal(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '=')
            return (1);
    return (0);
}

int var_equal(char *str, shell_t *shell)
{
    char **val = split_var(str);

    if (str_is_alpha_num(val[0]) == 1) {
        my_putstr_error(
        "set: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    if (val[1])
        pushback_var(val[0], val[1], &(shell->vars));
    else
        pushback_var(val[0], NULL, &(shell->vars));
    return (0);
}

int var_normal(char **argv, shell_t *shell, int *i)
{
    if (str_is_alpha_num(argv[*i]) == 1) {
        my_putstr_error(
        "set: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    if (!argv[*i + 1] || my_strcmp(argv[*i + 1], "=") != 0) {
        pushback_var(argv[*i], NULL, &(shell->vars));
        (*i)++;
        return (0);
    }
    if (argv[*i + 2]) {
        pushback_var(argv[*i], argv[*i + 2], &(shell->vars));
        *i += 3;
    } else {
        pushback_var(argv[*i], NULL, &(shell->vars));
        *i += 2;
    }
    return (0);
}

int make_var(char **argv, shell_t *shell)
{
    int eq = 0;
    int check = 0;

    for (int i = 0; argv[i] && check == 0;) {
        if (char_is_alpha(argv[i][0]) == 1) {
            my_putstr_error("set: Variable name must begin with a letter.\n");
            return (1);
        }
        eq = is_equal(argv[i]);
        if (eq == 1) {
            check = var_equal(argv[i], shell);
            i++;
        } else {
            check = var_normal(argv, shell, &i);
        }
    }
    return (0);
}