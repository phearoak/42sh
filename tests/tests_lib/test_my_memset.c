/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_memset, test_memset)
{
    char *str = malloc(sizeof(char) * 4);
    my_memset(str, '\0', 4);

    cr_assert_str_eq(str, "");
}
