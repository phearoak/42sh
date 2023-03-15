/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_split, test_split)
{
    char **av = my_split("hello", '\n');

    cr_assert_not_null(av);
}

Test(my_split, test_split2)
{
    char **av = my_split("hello\ntout\nle\nmonde", '\n');

    cr_assert_not_null(av);
}

Test(my_split, test_split3)
{
    char **av = my_split("hello\n\n", '\n');

    cr_assert_not_null(av);
}