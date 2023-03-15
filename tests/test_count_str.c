/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(count_str, test_count_str)
{
    char **av = malloc(sizeof(char *) * 3);
    int r = 0;

    av[0] = "ls";
    av[1] = "s*";
    av[2] = NULL;
    r = count_str(av);
    cr_assert_eq(r, 2);
}