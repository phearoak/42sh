/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** do redirection double left
*/

#include <minishell.h>
#include <my.h>

char **my_gettab(char *str)
{
    size_t len = 0;
    ssize_t nread;
    char **array = NULL;
    char *line = NULL;

    my_putstr("? ");
    nread = getline(&line, &len, stdin);
    while (nread != -1) {
        line[nread] = '\0';
        line[nread - 1] = '\0';
        if (my_strcmp(line, str) == 0)
            break;
        line[nread - 1] = '\n';
        array = my_add_to_tab(array, my_strdup(line));
        my_putstr("? ");
        nread = getline(&line, &len, stdin);
    }
    free(line);
    return (array);
}

void do_redirection_double_left(list_sh_t *cmd, int *pipes)
{
    char **array = my_gettab(cmd->command);

    dup2(pipes[1], 1);
    close(pipes[1]);
    close(pipes[0]);
    for (int i = 0; array[i]; i++) {
        my_putstr(array[i]);
    }
    exit(0);
}
