/*
** EPITECH PROJECT, 2020
** my strncmp
** File description:
** compare two string
*/

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    for (; str1[i] && str2[i] && i < n - 1; i++) {
        if (str1[i] - str2[i] != 0)
            return (str1[i] - str2[i]);
    }
    return (str1[i] - str2[i]);
}