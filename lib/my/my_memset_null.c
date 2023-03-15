/*
** EPITECH PROJECT, 2020
** memset
** File description:
** memset
*/

void my_memset_null(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = 0;
}
