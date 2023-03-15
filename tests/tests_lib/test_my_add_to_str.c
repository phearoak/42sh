/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_strncat_dup, test_add_to_str)
{
    char *str = my_strncat_dup("hello", "hello", 3);

    cr_assert_str_eq(str, "hellohel");
}

Test(my_strncat_dup, test_add_to_str2)
{
    char *str = my_strncat_dup("hello", "hello", 6);

    cr_assert_str_eq(str, "hellohello");
}