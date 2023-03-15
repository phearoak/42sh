/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** returns 1 if a string contains a string else it returns 0
*/

int my_strlen(char *);

int starts_with(char *string, char *target)
{
    for (int i = 0; target[i]; i++)
        if (string[i] != target[i])
            return (0);
    return (1);
}

int my_contains(char *string, char *target)
{
    int s_len;
    int t_len;
    int max;

    s_len = my_strlen(string);
    t_len = my_strlen(target);
    if (s_len < t_len)
        return (0);
    max = s_len - t_len;
    for (int i = 0; i <= max; i++)
        if (starts_with(&string[i], target))
            return (1);
    return (0);
}