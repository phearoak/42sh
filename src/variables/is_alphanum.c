/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** is alpha num
*/

int char_is_alpha_num(char c)
{
    if (!(c >= '0' && c <= '9') &&
    !(c >= 'a' && c <= 'z') &&
    !(c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int char_is_alpha(char c)
{
    if (!(c >= 'a' && c <= 'z') &&
    !(c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int char_is_num(char c)
{
    if (!(c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int str_is_alpha_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') &&
        !(str[i] >= 'a' && str[i] <= 'z') &&
        !(str[i] >= 'A' && str[i] <= 'Z'))
            return (1);
    }
    return (0);
}

int str_is_num(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
    }
    return (0);
}