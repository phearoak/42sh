/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** scripting parser
*/

#include <minishell.h>
#include <my.h>

static int parse_line(shell_t *shell, char **script, int *y)
{
    if (my_strncmp(script[(*y)], "if", 2) == 0) {
        return (parse_if(shell, script, y));
    }
    return (0);
}

void parse_script(shell_t *shell, char **script, char *filepath, int is_exec)
{
    list_sh_t *list;
    char **tmp = script;
    char *args[2];
    int y = 0;

    for (y = 0; tmp[y]; my_movestart(tmp[y++], ' '));
    y = 0;
    if (script[0][0] == '#' && script[0][1] == '!') {
        if (!is_exec) {
            args[0] = filepath;
            args[1] = NULL;
            execve(&script[0][2], args, shell->env);
            exit(1);
        }
        y += 1;
    }
    for (; script[y]; y++)
        if (!parse_line(shell, script, &y))
            do_line_before(&list, shell, script[y]);
}