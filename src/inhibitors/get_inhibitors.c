/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-nathan.guiu
** File description:
** get_inhibitors
*/

#include <string.h>
#include <stdlib.h>
#include <my.h>

char *get_inhib_char(char *str, char *tmp, int s_quote, int d_quote)
{
    if ((s_quote || d_quote) && str[1] == 'a')
        tmp[0] = '\a';
    if ((s_quote || d_quote) && str[1] == 'b')
        tmp[0] = '\b';
    if ((s_quote || d_quote) && str[1] == 't')
        tmp[0] = '\t';
    if ((s_quote || d_quote) && str[1] == 'n')
        tmp[0] = '\n';
    if ((s_quote || d_quote) && str[1] == 'v')
        tmp[0] = '\v';
    if ((s_quote || d_quote) && str[1] == 'f')
        tmp[0] = '\f';
    if ((s_quote || d_quote) && str[1] == 'r')
        tmp[0] = '\r';
    return (tmp);
}

char *get_inhib_char_quotes(char *str, int s_quote, int d_quote)
{
    char tmp[4] = {0, 0, 0, 0};
    char *result = NULL;

    if (s_quote || d_quote)
        tmp[0] = '\\';
    else
        tmp[0] = str[1];
    get_inhib_char(str, tmp, s_quote, d_quote);
    if ((s_quote || d_quote) && tmp[0] == '\\' \
    && str[1] != '\'' && str[1] != '"')
        tmp[1] = str[1];
    result = my_malloc(strlen(tmp) + 1);
    strcpy(result, tmp);
    return (result);
}

char *compute_inhibitors(char *arg)
{
    char tmp[strlen(arg) + 1];
    int s_quotes = 0;
    int d_quotes = 0;

    tmp[0] = 0;
    for (int i = 0; arg[i]; i++) {
        if (arg[i] == '\'')
            s_quotes++;
        if (arg[i] == '"')
            d_quotes++;
        if (arg[i] == '\'' || arg[i] == '"')
            continue;
        if (arg[i] == '\\') {
            strcat(tmp, get_inhib_char_quotes(&arg[i], \
            s_quotes % 2, d_quotes % 2));
            i++;
            continue;
        }
        strncat(tmp, &arg[i], 1);
    }
    return (strdup(tmp));
}

char *compute_inhibitors_cmd(char *arg)
{
    char tmp[strlen(arg) + 1];
    int s_quotes = 0;
    int d_quotes = 0;

    tmp[0] = 0;
    for (int i = 0; arg[i]; i++) {
        if (arg[i] == '\'')
            s_quotes++;
        if (arg[i] == '"')
            d_quotes++;
        if (arg[i] == '\'' || arg[i] == '"')
            continue;
        if (arg[i] == '\\' && s_quotes % 2 == 0 && d_quotes % 2 == 0) {
            strcat(tmp, get_inhib_char_quotes(&arg[i], \
            s_quotes % 2, d_quotes % 2));
            i++;
            continue;
        }
        strncat(tmp, &arg[i], 1);
    }
    return (strdup(tmp));
}

char **get_inhibitors(char **argv)
{
    if (argv && argv[0])
        argv[0] = compute_inhibitors_cmd(argv[0]);
    for (int i = 1; argv && argv[i]; i++)
        argv[i] = compute_inhibitors(argv[i]);
    return (argv);
}