/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** #inc
*/

#include <minishell.h>
#include <my.h>

void pre_execute_line_after(char ***argv, char **command,
shell_t *shell, char **all_path)
{
    (*argv) = get_argv((*argv), all_path, shell);
    if ((*argv) == NULL)
        return;
    (*command) = my_strdup((*argv)[0]);
    if (my_strcmp(*command, "ls") == 0 &&
    variable_is_set(shell, "color") == 1)
        *argv = my_add_to_tab(*argv, "--color=auto");
}

void check_echo_variable(char **argv, shell_t *shell)
{
    if (variable_is_set(shell, "echo") == 0)
        return;
    for (int i = 0; argv[i]; i++) {
        if (i > 0)
            my_putchar(' ');
        my_putstr(argv[i]);
    }
    my_putchar('\n');
}

int execute_line_after(list_sh_t **cmd, shell_t *shell)
{
    char *command = get_command_line((*cmd)->command);
    char **argv = get_argv_line((*cmd)->command);
    char **all_path = get_path(shell->env);
    char *path = NULL;
    int check = 0;

    if (command != NULL) {
        if (my_strcmp("exit", command) == 0)
            return (777);
        pre_execute_line_after(&argv, &command, shell, all_path);
        if (argv == NULL)
            return (84);
        path = find_path(all_path, command);
        check_echo_variable(argv, shell);
        if ((path != NULL && command_handling(command) == 0) ||\
        (*cmd)->separator == 5 || (*cmd)->separator == 4)
            check = execute_command_path_a(path, argv, shell, cmd);
        else
            check = exec_builtin_command(command, argv, shell, cmd);
    }
    return (check);
}