/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>
#include <my.h>

Test(my_movestart, test_my_movestart)
{
    char *str = strdup("hello");
    my_movestart(str, 'h');

    cr_assert_str_eq(str, "ello");
}

Test(my_movestart, test_my_movestart2)
{
    char *str = strdup("");
    my_movestart(str, 'h');

    cr_assert_str_eq(str, "");
}