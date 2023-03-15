/*
** EPITECH PROJECT, 2020
** my strncmp
** File description:
** copy n byte into a string
*/

#include <stdio.h>
#include <string.h>

void *my_malloc(int size);

char *my_strcat(char *s1, char *s2)
{
    char *dest = my_malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
    int i = 0;
    int a = 0;
    for (; s1[i]; ++i)
        dest[i] = s1[i];
    for (; s2[a]; ++i, ++a)
        dest[i] = s2[a];
    dest[i + 1] = '\0';
    return dest;
}