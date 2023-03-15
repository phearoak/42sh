/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** foreach
*/

#include <minishell.h>
#include <my.h>

int check_parent_forea(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            count = tab[i][j] == '(' ? count + 1 : count;
        }
    }
    return (count);
}

char **get_for_commands(shell_t *shell)
{
    char **tab = NULL;
    char *line = NULL;
    size_t len = 0;

    (void) shell;
    print_for();
    while (getline(&line, &len, stdin) != -1) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (my_strcmp(line, "end") == 0)
            return (tab);
        tab = my_add_to_tab(tab, line);
        print_for();
    }
    if (tab)
        return (tab);
    printf("foreach: end not found.\n");
    return (NULL);
}

int foreach_next(char **tab, char *var, shell_t *shell)
{
    char **commands = get_for_commands(shell);
    list_sh_t *list;

    if (!commands)
        return (0);
    for (int i = 0; tab[i]; i++) {
        pushback_var(var, tab[i], &shell->vars);
        for (int j = 0; commands[j]; j++) {
            do_line_before(&list, shell, commands[j]);
        }
    }
    return (0);
}

int make_foreach(char **argv, shell_t *shell)
{
    char **tab = NULL;

    for (int i = 2; argv[i]; i++) {
        if (my_strcmp("(", argv[i]) != 0 && my_strcmp(")", argv[i]) != 0 &&
        my_strcmp("", argv[i]) != 0)
            tab = my_add_to_tab(tab, argv[i]);
    }
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '(')
            tab[i]++;
        if (tab[i][strlen(tab[i]) - 1] == ')')
            tab[i][strlen(tab[i]) - 1] = 0;
    }
    return (foreach_next(tab, argv[1], shell));
}

int do_foreach(shell_t *shell, char **argv)
{
    int len = count_str(argv);

    if (len < 4) {
        my_putstr_error("foreach: Too few arguments.\n");
        return (1);
    }
    if (char_is_alpha(argv[1][0]) == 1) {
        my_putstr_error("foreach: Variable name must begin with a letter.\n");
        return (1);
    }
    if (str_is_alpha_num(argv[1]) == 1) {
        my_putstr_error(
        "foreach: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    if (check_parent_forea(argv) == 0) {
        my_putstr_error("foreach: Words not parenthesized.\n");
        return (1);
    }
    return (make_foreach(argv, shell));
}