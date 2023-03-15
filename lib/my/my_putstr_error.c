/*
** EPITECH PROJECT, 2020
** my_putstr error
** File description:
** print a string in error
*/

#include <unistd.h>

int my_strlen(char const *c);

int my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}