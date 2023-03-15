/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** exec builtins
*/

#include <minishell.h>
#include <my.h>

void before_exec_builtin(list_sh_t *cmd, int *pipes)
{
    if (cmd->pipes != NULL) {
        dup2(cmd->pipes[0], 0);
        close(cmd->pipes[0]);
    }
    if (cmd->separator == 1) {
        dup2(pipes[1], 1);
        close(pipes[1]);
        cmd->next->pipes = pipes;
        cmd->next->save_pipes = cmd->save_pipes;
    } else {
        check_child_redirection_next(cmd);
    }
}

void after_exec_builtin(list_sh_t *cmd)
{
    if (cmd->pipes != NULL) {
        dup2(cmd->save_pipes[0], 0);
        close(cmd->save_pipes[0]);
    }
    if (cmd->separator == 1) {
        dup2(cmd->save_pipes[1], 1);
        close(cmd->save_pipes[1]);
    }
}

int exec_builtin_command(char *command, char **argv, shell_t *shell, \
list_sh_t **cmd)
{
    int status = 0;
    int *pipes = check_create_pipes(*cmd);

    before_exec_builtin(*cmd, pipes);
    status = check_execute_command(command, argv, shell);
    after_exec_builtin(*cmd);
    reset_pipes(*cmd);
    return (status);
}