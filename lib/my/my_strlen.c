/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** return len of a string
*/

int my_wordlen(char **str)
{
    int size = 0;

    for (; str[size]; size++);
    return (size);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
