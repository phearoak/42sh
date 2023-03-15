/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(delete_slash, test_delete_slash)
{
    char *res = delete_slash("he\\ll\\o");

    cr_assert_str_eq(res, "hello");
}