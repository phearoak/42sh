/*
** EPITECH PROJECT, 2021
** get argv line
** File description:
** get argv line
*/

#include <minishell.h>
#include <my.h>

char *get_word(char *str, int *index)
{
    int size = 0;
    char *word = NULL;
    int quote = 0;

    for (int i = *index; (is_separator(str[i]) == 0 && str[i] != '\0') ||\
    (i != 0 && str[i - 1] == '\\') || (quote == 1  && str[i] != '\0'); i++) {
        if (str[i] == '`')
            quote = quote == 0 ? 1 : 0;
        size++;
    }
    word = malloc((size + 1) * sizeof(char));
    for (int i = *index; i < *index + size; i++)
        word[i - *index] = str[i];
    word[size] = 0;
    *index = *index + size;
    return (word);
}

argv_t *add_word(char *word, argv_t *list)
{
    argv_t *tmp = list;

    tmp = malloc(sizeof(argv_t));
    tmp->word = word;
    tmp->next = list;
    list = tmp;
    return (list);
}

char **make_list_to_array(argv_t *list)
{
    char **array = NULL;
    argv_t *first = list;
    int i = 0;

    while (list) {
        i++;
        list = list->next;
    }
    array = malloc(sizeof(char *) * (i + 1));
    list = first;
    for (i = 0; list; i++) {
        array[i] = list->word;
        list = list->next;
    }
    array[i] = NULL;
    return (array);
}

argv_t *reverse_list(argv_t *list)
{
    argv_t *reverse = NULL;
    argv_t *tmp = NULL;

    while (list) {
        tmp = reverse;
        reverse = malloc(sizeof(argv_t));
        reverse->word = list->word;
        reverse->next = tmp;
        list = list->next;
    }
    return (reverse);
}

char **get_argv_line(char *str)
{
    argv_t *list = NULL;
    char *word = NULL;

    for (int i = 0; str[i]; i++) {
        while (is_separator(str[i]) == 1)
            i++;
        if (str[i] != '\0') {
            word = get_word(str, &i);
            list = add_word(word, list);
        }
        if (str[i] == '\0')
            i--;
    }
    list = reverse_list(list);
    return (make_list_to_array(list));
}