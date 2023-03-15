/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** check redirection
*/

#include <minishell.h>

int *check_create_pipes(list_sh_t *cmd)
{
    int *pipes = NULL;

    if (cmd->separator == 4) {
        cmd->save_pipes[1] = dup(1);
        cmd->save_pipes[0] = dup(0);
        pipes = malloc(2 * sizeof(int));
        pipe(pipes);
        close(pipes[0]);
        pipes[0] = open(cmd->command, O_RDONLY);
    }
    if (cmd->separator == 1 || cmd->separator == 5) {
        pipes = malloc(2 * sizeof(int));
        pipe(pipes);
        cmd->save_pipes[1] = dup(1);
        cmd->save_pipes[0] = dup(0);
    }
    if (cmd->pipes != NULL) {
        cmd->save_pipes[0] = dup(0);
    }
    return (pipes);
}

void check_child_redirection_next(list_sh_t *cmd)
{
    int fd = 0;

    if (cmd->separator == 2 || cmd->separator == 3) {
        cmd->save_pipes[1] = dup(1);
        if (cmd->separator == 2)
            fd = open(cmd->file, O_WRONLY | O_CREAT | O_TRUNC, 00777);
        else
            fd = open(cmd->file, O_WRONLY | O_CREAT | O_APPEND, 00777);
        dup2(fd, 1);
        close(fd);
    }
    if (cmd->separator == 4) {
        exit(0);
    }
}

void check_child_redirection(list_sh_t *cmd, int *pipes)
{
    if (cmd->pipes != NULL) {
        dup2((cmd->pipes)[0], 0);
        close((cmd->pipes)[0]);
        close((cmd->pipes)[1]);
    }
    if (cmd->separator == 1) {
        dup2(pipes[1], 1);
        close(pipes[0]);
        close(pipes[1]);
        return;
    }
    if (cmd->separator == 5)
        do_redirection_double_left(cmd, pipes);
    check_child_redirection_next(cmd);
}

void check_parent_redirection(list_sh_t *cmd, int *pipes)
{
    if (cmd->separator == 1 || cmd->separator == 5) {
        cmd->next->pipes = pipes;
        cmd->next->save_pipes = cmd->save_pipes;
        dup2(cmd->save_pipes[1], 1);
        close(cmd->save_pipes[1]);
    }
    if (cmd->separator == 4) {
        cmd->next->pipes = pipes;
        cmd->next->save_pipes = cmd->save_pipes;
    }
    if (cmd->pipes != NULL) {
        close((cmd->pipes)[0]);
        close((cmd->pipes)[1]);
        dup2(cmd->save_pipes[0], 0);
        close(cmd->save_pipes[0]);
    }
}