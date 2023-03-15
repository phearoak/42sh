/*
** EPITECH PROJECT, 2020
** my strncmp
** File description:
** compare two string
*/

#include <stdio.h>

void *my_malloc(int size);

char *my_strncpy(char *str, int n)
{
    char *dest = my_malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++)
        dest[i] = str[i];
    return dest;
}