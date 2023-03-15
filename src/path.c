/*
** EPITECH PROJECT, 2021
** path
** File description:
** path
*/

#include <my.h>
#include <minishell.h>

char **get_path_default(void)
{
    char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:" \
    "/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";

    return (my_split(path, ':'));
}

char **get_path(char **env)
{
    char *str = NULL;
    char **array = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp("PATH=", env[i], 5) == 0) {
            str = env[i];
            str = str + 5;
            array = my_split(str, ':');
        }
    }
    if (array == NULL)
        array = get_path_default();
    return (array);
}

int check_slash(char *command)
{
    for (int i = 0; command[i]; i++)
        if (command[i] == '/')
            return (1);
    return (0);
}

int check_command_dir(char *command)
{
    struct stat sb;

    if (stat(command, &sb) != 0)
        return (0);
    if (S_ISDIR(sb.st_mode))
        return (1);
    return (0);
}

char *find_path(char **path, char *command)
{
    char *str = NULL;

    if (path == NULL || my_strncmp(command, "..", 2) == 0)
        return (NULL);
    if (access(command, F_OK) == 0 && check_slash(command) == 1 &&
    check_command_dir(command) == 0) {
        return (command);
    }
    for (int i = 0; path[i] != NULL; i++) {
        if (my_strcmp("/", path[i]) != 0) {
            str = my_strncat_dup(path[i], "/", 1);
            str = my_strncat_dup(str, command, my_strlen(command));
        }
        if (access(str, F_OK) == 0) {
            return (str);
        }
    }
    return (NULL);
}