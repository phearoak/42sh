/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** move str pointer until the pointer is not anymore on 'c'
*/

static void rotate_left(char *array, int target)
{
    int i = target;

    for (; array[i]; i++)
        array[i] = array[i+1];
    array[i-1] = 0;
}

void my_movestart(char *str, char c)
{
    if (*str == 0)
        return;
    while (*str != 0 && *str == c)
        rotate_left(str, 0);
}