/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** line termios
*/

#include <minishell.h>
#include <my.h>
#include <termios.h>

void get_key(int *key, int *spe, struct termios old,
struct termios new)
{
    (*spe) = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    (*key) = getchar();
    if ((*key) == 27) {
        (*spe) = 1;
        (*key) = getchar();
        (*key) = getchar();
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
}

void get_line_next_termios2(shell_t *shell, my_ter_t *ter, int arr)
{
    if (arr == 0)
        arr = del_key_ter(ter->key, &(ter->pos), &(ter->str), shell);
    if (arr == 0)
        arr = back_key_ter(ter->key, &(ter->pos), &(ter->str), shell);
    if (arr == 0)
        arr = end_key_ter(ter->key, &(ter->pos), ter->max_pos);
    if (ter->spe != 1 && arr == 0 && ter->key != 127)
        default_case(ter->key, &(ter->str), &(ter->pos));
}

void get_line_next_termios(shell_t *shell, my_ter_t *ter)
{
    int arr = 0;

    ter->max_pos = my_strlen(ter->str);
    if (ter->spe == 1) {
        arr = move_in_line_t(ter->key, &(ter->pos), ter->max_pos, shell);
        if (arr == 0)
            arr = arrow_up_t(ter->key, shell, &(ter->hist_pos), &(ter->str));
    }
    if (arr == 2) {
        if (ter->str[0] == ' ')
            ter->str++;
        ter->max_pos = strlen(ter->str);
        ter->pos = ter->max_pos;
    }
    get_line_next_termios2(shell, ter, arr);
}

char *get_line_termios(shell_t *shell, my_ter_t ter)
{
    struct termios old;
    struct termios new;

    ter.str = "";
    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~(ECHO | ICANON);
    while (1) {
        get_key(&(ter.key), &(ter.spe), old, new);
        if (ter.key == 4)
            return (NULL);
        if (ter.key == 10) {
            my_putchar('\n');
            return (check_rmstar(ter.str, shell));
        }
        get_line_next_termios(shell, &ter);
        ter.max_pos = my_strlen(ter.str);
        print_prompt_ter(ter.str, ter.pos, ter.max_pos, shell);
    }
    return (NULL);
}

char *line_termios(shell_t *shell)
{
    my_ter_t ter;

    ter.key = 0;
    ter.max_pos = 0;
    ter.pos = 0;
    ter.spe = 0;
    ter.str = "";
    ter.hist_pos = get_history_len(shell);
    printf("\0337");
    print_prompt_ter("", 0, 0, shell);
    return (get_line_termios(shell, ter));
}