/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_revstr, test_revstr)
{
    char *str = my_strdup("hello");
    char *t = my_revstr(str);

    cr_assert_str_eq(t, "olleh");
}
