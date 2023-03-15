/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** builtins
*/

#include <my.h>
#include <minishell.h>

int do_builtins(void)
{
    printf("alias   builtins   cd   chdir   echo\nexec   exit   glob   %s\n",
    "history   printenv\nrepeat   set   unalias   unset   where\nwhich");
    return (0);
}

int do_exec(shell_t *shell, char **argv)
{
    int len = count_str(argv);
    char **all_path = get_path(shell->env);
    char *path = NULL;

    if (len == 1) {
        my_putstr_error("exec: Too few arguments.");
        return (1);
    }
    path = find_path(all_path, argv[1]);
    if (path == NULL) {
        my_putstr_error(argv[1]);
        my_putstr_error(": Command not found.\n");
        return (1);
    }
    execve(path, argv + 1, shell->env);
    return (0);
}

int do_glob(shell_t *shell, char **argv)
{
    int len = count_str(argv);

    (void) shell;
    for (int i = 1; i < len; i++)
        my_putstr(argv[i]);
    return (0);
}

int do_printenv(shell_t *shell, char **argv)
{
    int len = count_str(argv);
    char *str = NULL;

    if (len == 1) {
        do_command_env(shell->env);
        return (0);
    }
    for (int i = 1; i < len; i++) {
        str = get_value_env(argv[i], shell->env);
        if (str)
            printf("%s\n", str);
    }
    return (0);
}