/*
** EPITECH PROJECT, 2021
** Minishell
** File description:
** Main
*/

#include <my.h>
#include <minishell.h>
#include <string.h>
#include <termios.h>

shell_t init_shell(void)
{
    shell_t shell;

    shell.check = 0;
    shell.check_error = 0;
    shell.exclamation_use = 0;
    shell.to_swap_cmd = NULL;
    shell.unavailable = NULL;
    shell.history = NULL;
    shell.reverse = NULL;
    shell.vars = NULL;
    shell.alias = NULL;
    shell.save = NULL;
    shell.tab = 0;
    shell.ncurse = 0;
    shell.ignoreeof = 1;
    shell.init_path = getcwd(NULL, 0);
    return (shell);
}

int check_help(int ac, char **av)
{
    if (ac == 1 || (ac >= 2 && my_strcmp(av[1], "-h") != 0))
        return (0);
    printf("USAGE\n\t./42sh (-n)\nDESCRIPTION\n\t%s",
    "Add -n flag to activate ncurse mode.\n");
    return (1);
}

void active_ncurse(shell_t *shell)
{
    (*shell).window = initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    shell->ncurse = 1;
    get_line_after(shell, shell->ncurse);
}

int main(int ac, char **av, char **env)
{
    shell_t shell = init_shell();

    shell.env = env;
    if (check_help(ac, av) == 1)
        return (0);
    if (ac >= 2) {
        run_scripting(&shell, "", &av[1], 1);
        return (0);
    }
    get_home(0, NULL, env);
    if (isatty(0) == 0)
        get_line_before(&shell);
    else {
        if (av[1] && my_strcmp(av[1], "-n") == 0) {
            active_ncurse(&shell);
        } else {
            get_line_after(&shell, 0);
        }
    }
    return (0);
}