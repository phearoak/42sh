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

Test(my_array_dup, test_my_array_dup)
{
    char **tab = NULL;
    char **new = NULL;

    tab = my_add_to_tab(tab, "ls");
    tab = my_add_to_tab(tab, "ls");
    new = my_array_dup(tab);

    cr_assert_str_eq(new[0], "ls");
}