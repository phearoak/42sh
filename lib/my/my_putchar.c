/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** put a char
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
