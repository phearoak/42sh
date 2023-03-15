/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(do_command_env, test_do_command_env)
{
    char **av = malloc(sizeof(char *) * 3);
    int r = 0;

    av[0] = "ls";
    av[1] = "s*";
    av[2] = NULL;
    r = do_command_env(av);
    cr_assert_eq(r, 0);
}