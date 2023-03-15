/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** scripting
*/

#include <minishell.h>
#include <my.h>

int open_script(char *filepath, char **content)
{
    int fd = -1;
    struct stat sb;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (0);
    if (stat(filepath, &sb))
        return (0);
    if (!S_ISREG(sb.st_mode))
        return (0);
    *content = malloc(sb.st_size + 1);
    if (!(*content))
        return (0);
    if (read(fd, *content, sb.st_size) == -1) {
        free(*content);
        return (0);
    }
    (*content)[sb.st_size] = 0;
    close(fd);
    return (1);
}

int read_script(char *content, char ***script)
{
    *script = my_str_to_word_array(content, "\n");
    if (!(*script))
        return (0);
    return (1);
}

int run_scripting(shell_t *shell, char *path, char **argv, int is_exec)
{
    char **script = NULL;
    char *content = NULL;
    char *filepath;

    filepath = argv[0];
    if (!filepath ||
    !open_script(filepath, &content) ||
    !read_script(content, &script)) {
        if (content)
            free(content);
        if (script)
            free_array(script);
        exec_failed(path);
        exit(1);
    }
    parse_script(shell, script, filepath, is_exec);
    free(content);
    free_array(script);
    exit(0);
}