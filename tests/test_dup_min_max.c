/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(dup_min_max, test_dup_min_max)
{
    char *str = dup_min_max("klhellokl", 2, 7);

    cr_assert_str_eq(str, "hello");
}