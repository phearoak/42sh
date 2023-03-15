/*
** EPITECH PROJECT, 2021
** My_str_to_word_array
** File description:
** returns an array of strings split from delimiter paramater
*/

#include <stdlib.h>
#include <my.h>

static void destroy_settings(settings_t *settings)
{
    if (!settings->result)
        return;
    for (int i = 0; settings->result[i]; free(settings->result[i++]));
    free(settings->result);
}

static int compare_str(settings_t *s, int index)
{
    for (int i = 0; s->dlm[i] != 0 && s->str[index]; i++, index++)
        if (s->str[index] != s->dlm[i])
            return (0);
    return (1);
}

static int translate_to_word(settings_t *s, int re, int *in)
{
    int size = 0;

    for (int i = *in ; !compare_str(s, i) && s->str[i]; i++, size++);
    s->result[re] = malloc(size + 1);
    if (!s->result[re])
        return (0);
    for (int i = 0; i <= size; s->result[re][i] = 0, i++);
    for (int i = 0; i < size; s->result[re][i] = s->str[*in], i++, *in += 1);
    if (s->str[*in] != '\0')
        *in += s->dlm_size;
    return (1);
}

char **my_str_to_word_array(char *str, char *dlm)
{
    settings_t settings;
    int index = 0;
    int total_size = 1;

    settings.str = str;
    settings.dlm = dlm;
    settings.dlm_size = my_strlen(settings.dlm);
    for (int i = 0; settings.str[i]; i++)
        if (compare_str(&settings, i))
            total_size++;
    settings.result = malloc(sizeof(char *) * (total_size + 1));
    if (!settings.result)
        return (NULL);
    for (int i = 0; i <= total_size; settings.result[i++] = NULL);
    for (int i = 0; i < total_size; i++) {
        if (!translate_to_word(&settings, i, &index)) {
            destroy_settings(&settings);
            return (NULL);
        }
    }
    return (settings.result);
}