/*
** EPITECH PROJECT, 2021
** check execute command
** File description:
** check execute command
*/

#include <my.h>
#include <minishell.h>

int do_implicitcd(shell_t *shell, char **argv)
{
    char **new = NULL;

    if (is_dir(argv[0]) == 84)
        return (1);
    new = my_add_to_tab(new, "cd");
    for (int i = 0; argv[i]; i++)
        new = my_add_to_tab(new, argv[i]);
    do_command_cd(new, &(shell->env));
    return (0);
}

int check_execute_command3(char *command, char **argv,
shell_t *shell)
{
    char *line = "";

    for (int i = 1; argv[i]; i++) {
        if (i > 2)
            line = my_strncat_dup(line, " ", 1);
        line = my_strncat_dup(line, argv[i], strlen(argv[i]));
    }
    if (my_strcmp("where", command) == 0)
        return (do_where(shell, argv));
    if (my_strcmp("which", command) == 0)
        return (do_which(shell, argv));
    if (my_strcmp("if", command) == 0)
        return (do_if(shell, line));
    if (my_strcmp("builtins", command) == 0)
        return (do_builtins());
    if (my_strncmp("history", command, 7) == 0)
        return (do_command_history(shell, command, argv));
    if (my_strcmp("foreach", command) == 0)
        return (do_foreach(shell, argv));
    return (command_not_exist(command));
}

int check_execute_command2(char *command, char **argv,
shell_t *shell)
{
    if (my_strcmp("set", command) == 0)
        return (do_variables(argv, shell));
    if (my_strcmp("unset", command) == 0)
        return (unset_variable(shell, argv));
    if (my_strcmp("alias", command) == 0)
        return (do_alias(argv, shell));
    if (my_strcmp("unalias", command) == 0)
        return (do_unalias(argv, shell));
    if (variable_is_set(shell, "implicitcd") == 1)
        return (do_implicitcd(shell, argv));
    if (my_strcmp("exec", command) == 0)
        return (do_exec(shell, argv));
    if (my_strcmp("glob", command) == 0)
        return (do_glob(shell, argv));
    if (my_strcmp("printenv", command) == 0)
        return (do_printenv(shell, argv));
    if (my_strcmp("repeat", command) == 0)
        return (do_repeat(shell, argv));
    return (check_execute_command3(command, argv, shell));
}

int check_execute_command(char *command, char **argv, shell_t *shell)
{
    int ret = 0;

    if (my_strcmp("cd", command) == 0 || my_strcmp("chdir", command) == 0) {
        ret = do_command_cd(argv, &(shell->env));
        do_spe_alias("cwdcmd", shell);
        return (ret);
    }
    if (my_strcmp("setenv", command) == 0)
        return (do_command_setenv(argv, &(shell->env)));
    if (my_strcmp("unsetenv", command) == 0)
        return (do_command_unsetenv(argv, &(shell->env)));
    if (my_strcmp("env", command) == 0)
        return (do_command_env(shell->env));
    if (my_strcmp("echo", command) == 0)
        return (do_command_echo(argv));
    if (my_strncmp("./", command, 2) == 0)
        return (do_command_binary(shell, command, argv));
    if (command[0] == '(')
        return (do_command_parent(argv, shell));
    return (check_execute_command2(command, argv, shell));
}

void reset_pipes(list_sh_t *cmd)
{
    if (cmd->separator == 2 || cmd->separator == 3) {
        dup2(cmd->save_pipes[1], 1);
        close(cmd->save_pipes[1]);
    }
    if (cmd->separator == 4 && cmd->pipes == NULL) {
        dup2(cmd->save_pipes[0], 0);
        close(cmd->save_pipes[0]);
    }
}