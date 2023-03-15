/*
** EPITECH PROJECT, 2020
** my strcmp
** File description:
** compare two string
*/

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    for (; str1[i] && str2[i]; i++) {
        if (str1[i] - str2[i] != 0)
            return (str1[i] - str2[i]);
    }
    return (str1[i] - str2[i]);
}