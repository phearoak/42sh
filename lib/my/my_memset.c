/*
** EPITECH PROJECT, 2020
** memset
** File description:
** memset
*/

void my_memset(char *str, char c, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = c;
}