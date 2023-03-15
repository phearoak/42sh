/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** tab key
*/

#include <minishell.h>
#include <my.h>
#include <glob.h>

char *get_word_tab(char *str, int pos)
{
    char *new = "";

    if (pos - 1 < 0)
        return (NULL);
    for (int i = pos - 1; i >= 0 && str[i] != ' '; i--)
        new = my_strncat_dup(new, &str[i], 1);
    if (new[0] == '\0')
        return (NULL);
    return (my_revstr(new));
}

// char **all_path = get_path();

int tab_key(int key, shell_t *shell, char **str, int *pos)
{
    char *pat = NULL;
    glob_t res;

    if (key == 9) {
        pat = get_word_tab(*str, *pos);
        ring_bell(shell);
        shell->tab = 1;
        if (pat == NULL) {
            printw("\n");
            return (1);
        }
        if (glob(my_strncat_dup(pat, "*", 1), 0, NULL, &res) == GLOB_NOMATCH) {
            printw("\n");
            return (1);
        }
        for (int i = 0; res.gl_pathv[i]; i++)
            printw("\n%s", res.gl_pathv[i]);
        printw("\n");
        return (1);
    }
    return (0);
}