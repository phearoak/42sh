/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** write in 'fd' the 'string'
*/

#include <unistd.h>
#include <my.h>

int my_writenextline(int fd, char *string)
{
    int string_len = 0;

    string_len = my_strlen(string);
    if (write(fd, string, string_len) != string_len)
        return (0);
    return (1);
}