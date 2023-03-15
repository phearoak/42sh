/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

char *get_time(void)
{
    char **date = NULL;
    char **all_hour = NULL;
    char *minutes = NULL;
    char *hour = NULL;
    char *tiret = my_malloc(sizeof(char) * 2);
    struct tm * timeinfo;
    time_t rawtime;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    tiret[0] = ':';
    tiret[1] = '\0';
    date = my_split( asctime(timeinfo), ' ');
    all_hour = my_split(date[3], ':');
    minutes = my_strncat_dup(tiret, all_hour[1], strlen(all_hour[1]));
    hour = my_strncat_dup(all_hour[0], minutes, strlen(minutes));
    return (hour);
}

void push_front_history_list(list_history_t **list, list_history_t *node)
{
    if (list == NULL || node == NULL)
        return;
    node->next = *list;
    *list = node;
}

void push_back_history_list(list_history_t **list, list_history_t *node)
{
    list_history_t *tmp;
    if (*list == NULL) {
        *list = node;
    } else {
        for (tmp = *list; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
}

list_history_t *create_history(char *command, char *hour, int *index)
{
    list_history_t *node = malloc(sizeof(*node));

    node->command = command;
    node->hour = hour;
    node->index = *index;
    node->next = NULL;
    return (node);
}

void add_command_in_history(shell_t *shell, \
char *command, int *index)
{
    char *hour = get_time();
    if (command[0] == '\n' && strlen(command) == 1)
        return;
    push_back_history_list(&shell->history, \
    create_history(command, hour, index));
    push_front_history_list(&shell->reverse, \
    create_history(command, hour, index));
    (*index)++;
    if (shell->exclamation_use == 1)
        printf("%s\n", command);
    shell->exclamation_use = 0;
}