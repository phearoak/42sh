/*
** EPITECH PROJECT, 2021
** do binary
** File description:
** do binary
*/

#include <errno.h>
#include <my.h>
#include <minishell.h>

int handle_segfault_binary(int status, int waiting)
{
    int exit;

    if (waiting == -1) {
        my_putstr_error("Can't wait for PID.\n");
        return (84);
    }
    if (!WIFSIGNALED(status))
        return (0);
    exit = WTERMSIG(status);
    if (exit == SIGSEGV)
        my_putstr_error("Segmentation fault\n");
    if (exit == SIGFPE)
        my_putstr_error("Floating exception\n");
    return (84);
}

void exec_failed(char *path)
{
    my_putstr_error(path);
    my_putstr_error(": ");
    my_putstr_error(strerror(errno));
    write(STDERR_FILENO, ".", 1);
    if (errno == ENOEXEC)
        my_putstr_error(" Wrong Architecture.\n");
    else
        write(STDERR_FILENO, "\n", 1);
}

int exec_binary(shell_t *shell, char *path, char **argv)
{
    int pid = 0;
    int status = 0;
    int waiting;

    pid = fork();
    if (pid == 0) {
        status = execve(path, argv, shell->env);
        if (status == -1)
            status = run_scripting(shell, path, argv, 0);
    }
    waiting = wait(&status);
    if (status != 0) {
        if (handle_segfault_binary(status, waiting) != 0)
            return (1);
    }
    return (WEXITSTATUS(status));
}

int do_command_binary(shell_t *shell, char *path, char **argv)
{
    int check = 0;

    if (access(path, F_OK) == 0) {
        check = exec_binary(shell, path, argv);
        return (check);
    }
    my_putstr_error(path);
    my_putstr_error(": Command not found.\n");
    return (1);
}