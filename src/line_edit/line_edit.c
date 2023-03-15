/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** line edition
*/

#include <minishell.h>
#include <my.h>
#include <line_edit.h>

void default_case(int key, char **str, int *pos)
{
    char c = key;
    int max = my_strlen(*str);

    if (*pos >= max)
        *str = add_at_index(my_strdup(*str), *pos, c);
    if (*pos < max) {
        *str = add_at_index(my_strdup(*str), *pos, c);
    }
    (*pos)++;
}

void part2(char **str, shell_t *shell, int *pos, int key)
{
    int max_pos = my_strlen(*str);

    if (move_in_line(key, pos, max_pos, shell) == 0 &&
    end_key(key, pos, max_pos) == 0 && del_key(key, pos, str, shell) == 0
    && scroll_key(key, shell) == 0)
        default_case(key, str, pos);
}

char *boucle_get(char **str, shell_t *shell, int key)
{
    int pos = 0;
    int max_pos = 0;
    int arr = 0;
    int hist_pos = get_history_len(shell);

    while ((key = getch())) {
        if (new_line(key) == 1  || tab_key(key, shell, str, &pos) == 1)
            return (*str);
        if (key == 4)
            return (NULL);
        if ((arr = arrow_up(key, shell, &hist_pos, str)) == 0)
            part2(str, shell, &pos, key);
        max_pos = my_strlen(*str);
        pos = (arr == 2) ? max_pos : pos;
        print_command(*str, pos, max_pos);
        refresh();
    }
    return (NULL);
}

char *line_ncu(shell_t *shell)
{
    char *str = "";
    shell->save = "";
    shell->tab = 0;

    print_first_prompt();
    return (boucle_get(&str, shell, 0));
}