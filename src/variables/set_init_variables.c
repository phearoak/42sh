/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** set initial variabls
*/

#include <minishell.h>
#include <my.h>

char **make_argv_init(char *name, char *value)
{
    char *new = "set ";

    new = my_strncat_dup(new, name, my_strlen(name));
    new = my_strncat_dup(new, " ", 1);
    new = my_strncat_dup(new, value, my_strlen(value));
    return (my_split(new, ' '));
}

void init_variables(shell_t *s)
{
    pushback_var("TERM", get_value_env("TERM", s->env), &(s->vars));
    pushback_var("term", get_value_env("TERM", s->env), &(s->vars));
    pushback_var("cwd", get_value_env("PWD", s->env), &(s->vars));
    pushback_var("owd", "", &(s->vars));
    pushback_var("gid", "1000", &(s->vars));
    pushback_var("group", get_value_env("GROUP", s->env), &(s->vars));
    pushback_var("home", get_value_env("HOME", s->env), &(s->vars));
    pushback_var("path", get_value_env("PATH", s->env), &(s->vars));
    pushback_var("user", get_value_env("USER", s->env), &(s->vars));
    pushback_var("pid", my_unatoi((int) getpid()), &(s->vars));
}