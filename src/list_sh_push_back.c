/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** list sh push back
*/

#include <my.h>
#include <minishell.h>

void fill_node_list_sh(list_sh_t *node, char *cmd, int op, char *file)
{
    node->command = cmd;
    node->separator = op;
    node->file = file;
    node->pipes = NULL;
    node->save_pipes = malloc(sizeof(int) * 2);
    node->next = NULL;
}

void change_str_command_redirect(char **command, char *file)
{
    int i = 0;
    char *after_file = NULL;

    for (; file[i] && file[i] != ' '; i++);
    if (file[i] == ' ') {
        file[i] = '\0';
        i++;
    }
    after_file = file + i;
    *command = my_strncat_dup(*command, " ", 1);
    *command = my_strncat_dup(*command, after_file, my_strlen(after_file));
    while (*command && **command == ' ')
        *command = *command + 1;
}

void list_sh_push_back(list_sh_t **list, char *cmd, int op, char *file)
{
    list_sh_t *node = malloc(sizeof(list_sh_t));
    list_sh_t *tmp = *list;

    if (file != NULL)
        change_str_command_redirect(&cmd, file);
    if (*list == NULL) {
        *list = node;
        fill_node_list_sh(node, cmd, op, file);
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    fill_node_list_sh(node, cmd, op, file);
    tmp->next = node;
}