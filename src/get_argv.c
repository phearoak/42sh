/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** get argv
*/

#include <minishell.h>
#include <my.h>

char **get_argv(char **argv, char **all_path, shell_t *shell)
{
    argv = get_variables(argv, shell);
    if (argv == NULL)
        return (NULL);
    argv = get_inhibitors(argv);
    if (argv == NULL)
        return (NULL);
    argv = do_backticks(argv, shell);
    if (argv == NULL)
        return (NULL);
    if (variable_is_set(shell, "noglob") == 0)
        argv = do_globbings(argv);
    if (argv == NULL)
        return (NULL);
    return (argv);
    (void) all_path;
}