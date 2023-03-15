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

Test(my_contains, test_my_contains)
{
    int v = my_contains("hello", "fr");

    cr_assert_eq(v, 0);
}

Test(my_contains, test_my_contains2)
{
    int v = my_contains("hello", "llo");

    cr_assert_eq(v, 1);
}