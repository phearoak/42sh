/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(do_globbings, test_do_globbings)
{
    char **av = malloc(sizeof(char *) * 3);
    char **tab = NULL;

    av[0] = "ls";
    av[1] = "s*";
    av[2] = NULL;
    tab = do_globbings(av);
    cr_assert_not_null(tab);
}

Test(do_globbings, test_do_globbings2)
{
    char **av = malloc(sizeof(char *) * 4);
    char **tab = NULL;

    av[0] = "ls";
    av[1] = "s";
    av[3] = NULL;
    tab = do_globbings(av);
    cr_assert_not_null(tab);
}

Test(do_globbings, test_do_globbings3)
{
    char **av = malloc(sizeof(char *) * 3);
    char **tab = NULL;

    av[0] = "ls";
    av[1] = "s[rm]?";
    av[2] = NULL;
    tab = do_globbings(av);
    cr_assert_not_null(tab);
}

Test(do_globbings, test_do_globbings4)
{
    char **av = malloc(sizeof(char *) * 3);
    char **tab = NULL;

    av[0] = "ls";
    av[1] = "s[rm]";
    av[2] = NULL;
    tab = do_globbings(av);
    cr_assert_null(tab);
}

Test(do_globbings, test_do_globbings5)
{
    char **av = malloc(sizeof(char *) * 3);
    char **tab = NULL;

    av[0] = "ls";
    av[1] = "s]";
    av[2] = NULL;
    tab = do_globbings(av);
    cr_assert_not_null(tab);
}

Test(do_globbings, test_do_globbings6)
{
    char **av = malloc(sizeof(char *) * 3);
    char **tab = NULL;

    av[0] = "ls";
    av[1] = "?";
    av[2] = NULL;
    tab = do_globbings(av);
    cr_assert_null(tab);
}