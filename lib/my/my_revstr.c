/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int len = 0;
    char temp;

    while (str[len] != '\0') {
        len++;
    }
    len--;
    for (int i = 0; i < len / 2 + 1; i++) {
        temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    return (str);
}
