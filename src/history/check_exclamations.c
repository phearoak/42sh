/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

char *get_command_exclamations(char *line, int index)
{
    char *cmd = NULL;
    int size = 0;
    int j = 0;

    for (int i = index; line[i] != '\0' && line[i] != ' ' &&
    line[i] != '\n'; i++, size++);
    cmd = malloc(sizeof(char) * size);
    for (int i = index; j < size; ++i, ++j)
        cmd[j] = line[i];
    cmd[size] = '\0';
    return (cmd);
}

int check_exclamation_exist(shell_t *shell, char *line, int index)
{
    if (line[index] == '!') {
        if (line[index + 1] == '=')
            return (1);
        char *cmd = get_command_exclamations(line, index);
        shell->unavailable = cmd;
        if (check_exclamation_number(shell->history, shell->reverse,
        shell, atoi(cmd+1))) {
            return (1);
        }
        if (check_exclamation_str(shell->reverse, shell, my_strdup(cmd+1))) {
            return (1);
        }
        if (check_exclamation_global(shell->reverse, shell, my_strdup(cmd+1))) {
            return (1);
        }
        if (check_exclamation_double(shell->reverse, shell, my_strdup(cmd+1))) {
            return (1);
        }
        return (0);
    }
    return (1);
}

int increment_i_value(int i, char *line)
{
    for (; line[i] != '\0' && line[i] != ' ' \
    && line[i] != '\n' && line[i] != '!'; i++);
    return (i);
}

int check_execute_exclamations(char *line, shell_t *shell)
{
    for (size_t i = 0; i < strlen(line); i++) {
        if (check_exclamation_exist(shell, line, i) == 0) {
            return (0);
        }
        if (line[i] == '!') {
            i++;
            i = increment_i_value(i, line);
        }
    }
    return (1);
}