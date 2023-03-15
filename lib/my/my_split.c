/*
** EPITECH PROJECT, 2021
** split
** File description:
** split
*/

#include <unistd.h>
#include <stdlib.h>

int nb_split(char *av, char c)
{
    int nb = 1;

    for (int i = 0; av[i]; i++) {
        while (av[i] == c)
            i++;
        if (av[i] != '\0')
            nb++;
        if (av[i] == '\0')
            return (nb);
    }
    return (nb);
}

char *my_split_do_str(char *str, int *index, char c)
{
    int tmp = *index;
    int size = 0;
    char *split = NULL;

    for (int i = tmp; str[i] != '\0' && str[i] != c; i++)
        size++;
    split = malloc(size + 1);
    for (int i = 0; str[*index] != '\0' && str[*index] != c; i++) {
        split[i] = str[*index];
        *index = *index + 1;
    }
    *index = *index - 1;
    split[size] = 0;
    return (split);
}

void memset_double_array(char **array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = NULL;
}

char **my_split(char *av, char c)
{
    char **array = malloc((nb_split(av, c) + 1) * sizeof(char *));
    int nb = 0;
    int i = 0;

    memset_double_array(array, (nb_split(av, c) + 1));
    for (i = 0; av[i]; i++) {
        while (av[i] == c)
            i++;
        if (av[i] != '\0') {
            array[nb] = my_split_do_str(av, &i, c);
            nb++;
        }
        if (av[i] == '\0')
            return (array);
    }
    return (array);
}