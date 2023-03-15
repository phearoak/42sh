/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** get key
*/

#include <minishell.h>
#include <my.h>
#include <termios.h>

void print_prompt_ter(char *str, int pos, int max_pos, shell_t *shell)
{
    char *branch = load_file(my_strncat_dup(shell->init_path, "/.git/HEAD",
    10));
    char **split = NULL;

    if (branch)
        split = my_split(branch, '/');
    printf("\0338");
    printf("\033[0J");
    printf("\033[2K");
    if (split && split[2]) {
        split[2][strlen(split[2]) - 1] = 0;
        printf("\e[32m%s \e[96m%s\e[32m> \e[39m%s",
        getcwd(NULL, 0), split[2], str);
    } else
        printf("\e[32m%s> \e[39m%s", getcwd(NULL, 0), str);
    if (pos < max_pos) {
        cursleft(max_pos - pos);
    }
    fflush(stdout);
}

// Ctrl + A
// Ctrl + D