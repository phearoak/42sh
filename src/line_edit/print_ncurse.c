/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** print prompt and line
*/

#include <minishell.h>
#include <my.h>

int new_line(int key)
{
    if (key == '\n') {
        printf("\n\r");
        printw("\n");
        fflush(stdout);
        return (1);
    }
    return (0);
}

char *get_branch(void)
{
    char *branch = load_file(".git/HEAD");
    char **split = NULL;

    if (branch)
        split = my_split(branch, '/');
    printf("'%s'\n", branch);
    if (split && split[2]) {
        split[2][strlen(split[2]) - 1] = 0;
        return (split[2]);
    }
    return (NULL);
}

void print_command(char *str, int pos, int max_pos)
{
    char *branch = get_branch();

    printf("\0338");
    printf("\033[0J");
    printf("\033[0K");
    if (branch)
        printf("\e[32m%s \e[96m%s\e[32m> \e[39m%s",
        getcwd(NULL, 0), branch, str);
    else
        printf("\e[32m%s> \e[39m%s", getcwd(NULL, 0), str);
    if (max_pos == 0) {
        fflush(stdout);
        return;
    }
    if (pos == 0) {
        cursorbackward(max_pos);
    } else if (pos < max_pos) {
        cursorbackward(max_pos - pos);
    }
    fflush(stdout);
}

void print_first_prompt(void)
{
    write(1, "\e[32m", 6);
    write(1, "\033[1A", 5);
    addstr(getcwd(NULL, 0));
    addstr("> ");
}