/*
** EPITECH PROJECT, 2021
** get line before
** File description:
** get line before binary
*/

#include <my.h>
#include <minishell.h>
#include <errno.h>

int execute_line_before(list_sh_t **cmd, shell_t *shell)
{
    char *command = get_command_line((*cmd)->command);
    char **argv = get_argv_line((*cmd)->command);
    char **all_path = get_path(shell->env);
    char *path = NULL;
    int check = 0;

    if (command != NULL) {
        if (my_strcmp("exit", command) == 0)
            return (777);
        argv = get_argv(argv, all_path, shell);
        if (argv == NULL)
            return (1);
        command = my_strdup(argv[0]);
        path = find_path(all_path, command);
        if ((path != NULL && command_handling(command) == 0) ||\
        (*cmd)->separator == 4) {
            check = execute_command_path_b(path, argv, shell, cmd);
        } else
            check = exec_builtin_command(command, argv, shell, cmd);
    }
    return (check);
}

void get_line_before_next(shell_t *shell, list_sh_t **list)
{
    while (*list) {
        shell->check = execute_line_before(list, shell);
        pushback_var("?", my_unatoi(shell->check), &(shell->vars));
        if (check_exit_and_or(&shell->check, &shell->check_error, list) == -1)
            break;
        *list = (*list)->next;
    }
    if (shell->check_error == 1)
        exit(shell->check);
}

void do_line_before(list_sh_t **list, shell_t *shell, char *line)
{
    line = get_alias(line, shell);
    if (line == NULL)
        return;
    if (get_list_sh_command(my_strdup(line), list) == -1)
        exit(1);
    get_line_before_next(shell, list);
}

void get_line_before(shell_t *shell)
{
    char *line = NULL;
    size_t len = 0;
    list_sh_t *list = NULL;

    while (getline(&line, &len, stdin) != -1) {
        do_line_before(&list, shell, line);
    }
    if (errno == ENOENT)
        exit(0);
    exit(shell->check);
}