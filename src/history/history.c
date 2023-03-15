/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

int badly_formed_number(shell_t *shell, char **argv)
{
    int a = 0;
    for (int i = 1; argv[i]; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            free_history(shell);
            a = 1;
            continue;
        }
        if (atoi(argv[i]) <= 0) {
            printf("history: Badly formed number.\n");
            return (1);
        }
    }
    return (a);
}

int do_command_history(shell_t *shell, char *command, char **argv)
{
    (void) command;
    if (badly_formed_number(shell, argv))
        return (0);
    for (list_history_t *tmp = shell->history; tmp != NULL; tmp = tmp->next) {
        printf("     %d  %s   %s\n", tmp->index, tmp->hour,
        tmp->command);
        fflush(stdout);
    }
    return (0);
}

char *str_replace(char *orig, char *rep, char *with)
{
    char *tmp = strstr(orig, rep);
    char *cpy = my_strncpy(orig, strlen(orig) - strlen(tmp));

    orig = my_strcat(cpy, with);
    orig = my_strcat(orig, tmp + strlen(rep));
    return (orig);
}

char *remplace_command_history(list_history_t *history, char *line,
int len, char *command)
{
    char *replace = NULL;

    for (list_history_t *tmp = history; tmp != NULL; tmp = tmp->next)
        if (tmp->index == len)
            replace = str_replace(line, command, tmp->command);
    return (replace);
}

char *check_command_exclamation(char *line, shell_t *shell)
{
    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] == '!') {
            if (line[i+1] != '\0' && line[i+1] != '=') {
                check_exclamation_exist(shell, line, i);
                line = str_replace(line, shell->unavailable,
                shell->to_swap_cmd);
            }
            i++;
            for (; line[i] != '\0' && line[i] != ' ' && line[i]
            != '\n' && line[i] != '!'; i++);
        }
    }
    return (line);
}