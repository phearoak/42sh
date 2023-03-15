/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** backticks
*/

#include <my.h>
#include <minishell.h>

char **get_exec(char *command, char **tab)
{
    FILE *fp;
    char pass[1035];
    char **new = NULL;

    for (int i = 0; tab && tab[i]; i++)
        new = my_add_to_tab(new, tab[i]);
    fp = popen(command, "r");
    while (fgets(pass, sizeof(pass), fp) != NULL) {
        pass[my_strlen(pass) - 1] = 0;
        if (my_strcmp(pass, "") != 0)
            new = my_add_to_tab(new, pass);
    }
    pclose(fp);
    return (new);
}

char **get_argv_backtic(char **argv)
{
    char **tab = NULL;
    int start = 0;
    char *tmp = "";

    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '`')
            start = 1;
        if (start == 1) {
            tmp = my_strncat_dup(tmp, " ", 1);
            tmp = my_strncat_dup(tmp, argv[i], strlen(argv[i]));
        } else {
            tab = my_add_to_tab(tab, argv[i]);
        }
        if (argv[i][strlen(argv[i]) - 1] == '`') {
            start = 0;
            tab = my_add_to_tab(tab, tmp + 1);
        }
    }
    return (tab);
}

char *add_path(char *str, char **all_path)
{
    char *new = "";
    char **tab = split_sh_command(str);
    char **tab_tmp = NULL;
    char *tmp = NULL;
    str[strlen(str) - 1] = 0;
    tab = split_sh_command(str);
    for (int i = 0; tab[i]; i++) {
        tab_tmp = my_split(tab[i], ' ');
        if (my_strcmp(tab_tmp[0], "echo") != 0)
            tmp = find_path(all_path, tab_tmp[0]);
        new = my_strncat_dup(new, " ", 1);
        if (tmp)
            new = my_strncat_dup(new, tmp, strlen(tmp));
        else
            new = my_strncat_dup(new, tab_tmp[0], strlen(tab_tmp[0]));
        for (int j = 1; tab_tmp[j]; j++) {
            new = my_strncat_dup(new, " ", 1);
            new = my_strncat_dup(new, tab_tmp[j], strlen(tab_tmp[j]));
        }
    }
    return (new + 1);
}

char **make_backticks(char **argv, shell_t *shell)
{
    char **tab = NULL;

    argv = get_argv_backtic(argv);
    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '`') {
            argv[i] = add_path(argv[i] + 1, get_path(shell->env));
            tab = get_exec(argv[i], tab);
        } else
            tab = my_add_to_tab(tab, argv[i]);
    }
    return (tab);
}

char **do_backticks(char **argv, shell_t *shell)
{
    int check = 0;

    for (int i = 0; argv[i]; i++) {
        for (int j = 0; argv[i][j]; j++) {
            check = check_backtick(argv[i][j], check);
        }
    }
    if (check == 0)
        return (argv);
    if (check % 2 == 1) {
        my_putstr_error("Unmatched '`'.\n");
        return (NULL);
    }
    return (make_backticks(argv, shell));
}

// CTRL + U
// CTRL + K