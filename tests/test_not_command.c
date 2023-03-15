/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(command_not_exist, test_command_not_exist)
{
    int r = command_not_exist(NULL);

    cr_assert_eq(r, 0);
}

Test(command_not_exist, test_command_not_exist2)
{
    int r = command_not_exist("dfgh");

    cr_assert_eq(r, 1);
}