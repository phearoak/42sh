/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** builtins
*/

#include <my.h>
#include <minishell.h>

int exec_repeat(shell_t *shell, int count, char **argv)
{
    list_sh_t *list;
    char *line = "";

    for (int i = 2; argv[i]; i++) {
        if (i > 2)
            line = my_strncat_dup(line, " ", 1);
        line = my_strncat_dup(line, argv[i], strlen(argv[i]));
    }
    for (int i = 0; i < count; i++) {
        do_line_before(&list, shell, line);
    }
    return (0);
}

int do_repeat(shell_t *shell, char **argv)
{
    int len = count_str(argv);
    int count = 0;

    if (len <= 2) {
        my_putstr_error("repeat: Too few arguments.\n");
        return (1);
    }
    if (str_is_num(argv[1]) == 1) {
        my_putstr_error("repeat: Badly formed number.\n");
        return (1);
    }
    count = my_atoi(argv[1]);
    return (exec_repeat(shell, count, argv));
}