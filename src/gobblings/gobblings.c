/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** globbings
*/

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <my.h>
#include <minishell.h>
#include <glob.h>

void update_globbings(char **gobs, char ***tab, int ret, int *err)
{
    if (ret == GLOB_ABORTED || ret == GLOB_NOMATCH) {
        *err = 1;
        return;
    }
    for (int i = 0; gobs[i]; i++) {
        *tab = my_add_to_tab(*tab, gobs[i]);
    }
}

char **return_glob(char **tab, int err)
{
    if (err == 1) {
        my_putstr_error(tab[0]);
        my_putstr_error(": No match.\n");
        return (NULL);
    }
    return (tab);
}

char **do_globbings(char **av)
{
    char **tab = NULL;
    glob_t result;
    int ret = 0;
    int err = 0;

    if (check_is_globbing(av) == 0)
        return (av);
    for (int i = 0; av[i]; i++) {
        if (is_there_a_globbing(av[i], 0) == 1) {
            ret = glob(av[i], 0, NULL, &result);
            update_globbings(result.gl_pathv, &tab, ret, &err);
        } else
            tab = my_add_to_tab(tab, av[i]);
    }
    globfree(&result);
    return (return_glob(tab, err));
}