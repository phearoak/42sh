/*
** EPITECH PROJECT, 2021
** get line after
** File description:
** get line after binary
*/

#include <my.h>
#include <minishell.h>

void get_line_after_next(shell_t *shell, list_sh_t **list)
{
    while (*list) {
        shell->check = execute_line_after(list, shell);
        pushback_var("?", my_unatoi(shell->check), &(shell->vars));
        if (check_exit_and_or(&shell->check, &shell->check_error, list) == -1)
            break;
        *list = (*list)->next;
    }
    if (shell->check_error == 1) {
        my_putstr("exit\n");
        endwin();
        exit(shell->check);
    }
}

char *screen_mode(int ncurses, shell_t *shell, int *get)
{
    char *line = NULL;

    do_spe_alias("precmd", shell);
    if (ncurses == 1) {
        line = line_ncu(shell);
        *get = 1;
    } else {
        line = line_termios(shell);
        *get = 1;
    }
    if (*get != -1)
        do_spe_alias("postcmd", shell);
    return (line);
}

void prepare_line(shell_t *shell, char *line, int *index)
{
    list_sh_t *list = NULL;

    if (line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = 0;
    line = get_alias(line, shell);
    if (line[0] == ' ')
        line++;
    if (check_execute_exclamations(my_strdup(line), shell)) {
        line = check_command_exclamation(my_strdup(line), shell);
        add_command_in_history(shell, strdup(line), index);
        if (get_list_sh_command(my_strdup(line), &list) == -1)
            return;
        get_line_after_next(shell, &list);
    } else {
        event_not_found(shell);
    }
}

void get_line_after(shell_t *shell, int ncurses)
{
    char *line = NULL;
    int get = 1;
    int index = 1;

    init_variables(shell);
    line = screen_mode(ncurses, shell, &get);
    while (line != NULL && get != -1) {
        pushback_var("cwd", get_value_env("PWD", shell->env), &(shell->vars));
        pushback_var("owd", get_value_env("OLDPWD", shell->env),
        &(shell->vars));
        if (shell->tab == 0)
            prepare_line(shell, line, &index);
        line = screen_mode(shell->ncurse, shell, &get);
    }
    my_putstr("exit\n");
    endwin();
}