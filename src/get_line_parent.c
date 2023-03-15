/*
** EPITECH PROJECT, 2021
** get line after
** File description:
** get line after binary
*/

#include <my.h>
#include <minishell.h>

int execute_line_parent(list_sh_t **cmd, shell_t *shell)
{
    char *command = get_command_line((*cmd)->command);
    char **argv = get_argv_line((*cmd)->command);
    char **all_path = get_path(shell->env);
    char *path = NULL;
    int check = 0;

    if (command != NULL) {
        if (my_strcmp("exit", command) == 0)
            return (777);
        path = find_path(all_path, command);
        if ((path != NULL && command_handling(command) == 0) ||\
        (*cmd)->separator == 5 || (*cmd)->separator == 4) {
            check = execute_command_path_p(path, argv, shell, cmd);
        } else {
            check = exec_builtin_command(command, argv, shell, cmd);
        }
        if (check != 0)
            return (check);
    }
    return (0);
}

int get_line_parent(char *line, shell_t *shell)
{
    list_sh_t *list = NULL;
    int check = 0;

    if (get_list_sh_command(my_strdup(line), &list) == -1)
        return (1);
    while (list) {
        check = execute_line_parent(&list, shell);
        pushback_var("?", my_unatoi(shell->check), &(shell->vars));
        if (check == 777)
            check = 0;
        if (check == 0 && list->separator == 6)
            jump_command_until_semicolon(&list);
        if (check != 0 && list->separator == 7)
            jump_command_until_semicolon(&list);
        list = list->next;
    }
    return (check);
}

void save_and_exec(shell_t *shell, char *line)
{
    char *save_pwd = NULL;
    char *save_oldpwd = NULL;
    char **restore_oldpwd = NULL;
    char **save_env = NULL;

    save_env = my_array_dup(shell->env);
    save_pwd = get_value_env("PWD", shell->env);
    save_oldpwd = get_value_env("OLDPWD", shell->env);
    get_line_parent(line, shell);
    do_cd_direct(save_pwd, &shell->env);
    shell->env = my_array_dup(save_env);
    if (save_oldpwd) {
        restore_oldpwd = my_add_to_tab(restore_oldpwd, "setenv");
        restore_oldpwd = my_add_to_tab(restore_oldpwd, "OLDPWD");
        restore_oldpwd = my_add_to_tab(restore_oldpwd, save_oldpwd);
    }
}

int do_command_parent(char **argv , shell_t *shell)
{
    char *line = "";

    for (int i = 0; argv[i]; i++) {
        line = my_strncat_dup(line, argv[i], my_strlen(argv[i]));
        if (argv[i + 1])
            line = my_strncat_dup(line, " ", 1);
    }
    line = line + 1;
    line[my_strlen(line) - 1] = '\0';
    save_and_exec(shell, line);
    return (0);
}