/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** include
*/

#ifndef __MY_H__
#define __MY_H__

typedef struct settings_s
{
    char **result;
    char *dlm;
    char *str;
    int dlm_size;
}settings_t;

int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
void my_memset(char *str, char c, int size);
void *my_malloc(int size);
char **my_split(char *av, char c);
char *my_strncat_dup(char *dest, char const *src, int nb);
void my_memset_null(char *str, int size);
int my_strcmp(char const *s1, char const *s2);
int my_putstr_error(char const *str);
char *my_strdup(char *str);
char **my_add_to_tab(char **tab, char *str);
char *my_strcat(char *s1, char *s2);
char *my_strncpy(char *str, int n);
char **my_array_dup(char **map);
char *my_unatoi(int nb);
int my_atoi(char *str);
void free_array(char **);
char **my_str_to_word_array(char *str, char *dlm);
int my_contains(char *string, char *target);
void my_movestart(char *str, char c);
int my_writenextline(int fd, char *string);
void my_replaceend(char *str, char c, char target);
int my_wordlen(char **str);
char *load_file(char *filepath);
char *my_strdup_target(char *str, int min, int max);

#endif
