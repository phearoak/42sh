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

Test(add_at_index, test_add_at_index)
{
    char *str = add_at_index("helo", 2, 'l');

    cr_assert_str_eq(str, "hello");
}

Test(add_at_index, test_add_at_index2)
{
    char *str = add_at_index("hell", 50, 'o');

    cr_assert_str_eq(str, "hello");
}

Test(remove_at_index, test_remove_at_index)
{
    char *str = remove_at_index(my_strdup("helllo"), 2);

    cr_assert_str_eq(str, "hello");
}

Test(remove_at_index, test_remove_at_index2)
{
    char *str = remove_at_index(my_strdup("hello"), 20);

    cr_assert_str_eq(str, "hello");
}

Test(remove_at_index, test_remove_at_index3)
{
    char *str = remove_at_index(my_strdup("ls"), 1);

    cr_assert_str_eq(str, "l");
}