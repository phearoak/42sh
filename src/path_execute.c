/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** execute path command
*/

#include <minishell.h>

int exec_second_command_pipes(list_sh_t **cmd, shell_t *shell, \
int (*func)(list_sh_t **cmd, shell_t *shell))
{
    int check = 0;

    if ((*cmd)->separator == 1) {
        *cmd = (*cmd)->next;
        check = func(cmd, shell);
    }
    return (check);
}

int end_fork_return(int check)
{
    int waiting = 0;
    int status = 0;
    int ret = 0;

    waiting = wait(&status);
    ret = WEXITSTATUS(status);
    check_segfault(status, waiting);
    if (ret == 0 && check != 0)
        return (check);
    return (ret);
}

int execute_command_path_a(char *path, char **argv, shell_t *shell, \
list_sh_t **cmd)
{
    int pid = 0;
    int status = 0;
    int *pipes = check_create_pipes(*cmd);
    int check = 0;

    if (argv == NULL)
        return (1);
    pid = fork();
    if (pid == 0) {
        check_child_redirection(*cmd, pipes);
        status = execve(path, argv, shell->env);
        check_incompatible_binary(path, status);
    } else {
        check_parent_redirection(*cmd, pipes);
        check = exec_second_command_pipes(cmd, shell, execute_line_after);
    }
    return (end_fork_return(check));
}

int execute_command_path_b(char *path, char **argv, shell_t *shell, \
list_sh_t **cmd)
{
    int pid = 0;
    int status = 0;
    int *pipes = check_create_pipes(*cmd);
    int check = 0;

    if (argv == NULL)
        return (1);
    pid = fork();
    if (pid == 0) {
        check_child_redirection(*cmd, pipes);
        status = execve(path, argv, shell->env);
        check_incompatible_binary(path, status);
    } else {
        check_parent_redirection(*cmd, pipes);
        check = exec_second_command_pipes(cmd, shell, execute_line_before);
    }
    return (end_fork_return(check));
}

int execute_command_path_p(char *path, char **argv, shell_t *shell, \
list_sh_t **cmd)
{
    int pid = 0;
    int status = 0;
    int *pipes = check_create_pipes(*cmd);
    int check = 0;

    if (argv == NULL)
        return (1);
    pid = fork();
    if (pid == 0) {
        check_child_redirection(*cmd, pipes);
        status = execve(path, argv, shell->env);
        check_incompatible_binary(path, status);
    } else {
        check_parent_redirection(*cmd, pipes);
        check = exec_second_command_pipes(cmd, shell, execute_line_parent);
    }
    return (end_fork_return(check));
}