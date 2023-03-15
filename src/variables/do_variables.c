/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** variables
*/

#include <variables.h>
#include <minishell.h>
#include <my.h>

void pushback_var(char *name, char *value, var_t **list)
{
    if (*list) {
        if (my_strcmp((*list)->name, name) == 0 && value == NULL) {
            (*list)->value = NULL;
            return;
        }
        if (my_strcmp((*list)->name, name) == 0) {
            (*list)->value = my_strdup(value);
            return;
        }
        pushback_var(name, value, &((*list)->next));
        return;
    }
    *list = my_malloc(sizeof(var_t));
    (*list)->next = NULL;
    (*list)->name = my_strdup(name);
    if (value != NULL)
        (*list)->value = delete_slash(value);
    else
        (*list)->value = my_strdup("");
}

char **split_var(char *str)
{
    char **tab = my_malloc(sizeof(char *) * 3);
    char *word = "";
    int ind = 0;

    tab[2] = NULL;
    for (; str[ind] && str[ind] != '='; ind++)
        word = my_strncat_dup(word, &str[ind], 1);
    tab[0] = my_strdup(word);
    tab[1] = my_strdup(str + ind + 1);
    return (tab);
}

int do_variables(char **argv, shell_t *shell)
{
    if (!argv[1]) {
        print_all_vars(shell);
        return (0);
    }
    if (argv[1][my_strlen(argv[1]) - 1] == '=' && argv[2])
        return (0);
    if ((argv[2] && argv[2][0] == '=' && my_strlen(argv[2]) > 1) ||
    (char_is_alpha(argv[1][0]) == 1)) {
        my_putstr_error("set: Variable name must begin with a letter.\n");
        return (1);
    }
    return (make_var(argv + 1, shell));
}