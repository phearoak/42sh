/*
** EPITECH PROJECT, 2020
** day07
** File description:
** concatenate the n fisrt bytes of src
*/

#include <stdlib.h>

void my_memset_null(char *str, int size);

int my_strlen(char const *str);

void *my_malloc(int size);

char *my_strncat_dup(char *dest, char const *src, int nb)
{
    int len_dest = 0;
    int i = 0;
    char *result = my_malloc(my_strlen(dest) + nb + 2);

    my_memset_null(result, my_strlen(dest) + nb + 2);
    for (; dest[len_dest]; len_dest++)
        result[len_dest] = dest[len_dest];
    for (; i < nb && src[i]; i++)
        result[len_dest + i] = src[i];
    result[len_dest + i] = '\0';
    return (result);
}
