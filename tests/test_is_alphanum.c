/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <minishell.h>

Test(char_is_alpha_num, test_char_is_alpha_num)
{
    int r = char_is_alpha_num('b');

    cr_assert_eq(r, 0);
}

Test(char_is_alpha_num, test_char_is_alpha_num2)
{
    int r = char_is_alpha_num('(');

    cr_assert_eq(r, 1);
}

Test(char_is_alpha_num, test_char_is_alpha_num3)
{
    int r = char_is_alpha_num('6');

    cr_assert_eq(r, 0);
}

Test(char_is_alpha_num, test_char_is_alpha_num4)
{
    int r = char_is_alpha_num('A');

    cr_assert_eq(r, 0);
}

Test(char_is_alpha_num, test_char_is_alpha_num5)
{
    int r = char_is_alpha_num('@');

    cr_assert_eq(r, 1);
}

Test(char_is_alpha_num, test_char_is_alpha_num6)
{
    int r = char_is_alpha_num('[');

    cr_assert_eq(r, 1);
}

Test(char_is_alpha_num, test_char_is_alpha_num7)
{
    int r = char_is_alpha_num('|');

    cr_assert_eq(r, 1);
}

Test(char_is_alpha, test_char_is_alpha)
{
    int r = char_is_alpha('a');

    cr_assert_eq(r, 0);
}

Test(char_is_alpha, test_char_is_alpha2)
{
    int r = char_is_alpha('Z');

    cr_assert_eq(r, 0);
}

Test(char_is_alpha, test_char_is_alpha3)
{
    int r = char_is_alpha('0');

    cr_assert_eq(r, 1);
}

Test(char_is_alpha, test_char_is_alpha4)
{
    int r = char_is_alpha('[');

    cr_assert_eq(r, 1);
}

Test(char_is_alpha, test_char_is_alpha5)
{
    int r = char_is_alpha('{');

    cr_assert_eq(r, 1);
}

Test(str_is_alpha_num, test_str_is_alpha_num)
{
    int r = str_is_alpha_num("b");

    cr_assert_eq(r, 0);
}

Test(str_is_alpha_num, test_str_is_alpha_num2)
{
    int r = str_is_alpha_num("(");

    cr_assert_eq(r, 1);
}

Test(str_is_alpha_num, test_str_is_alpha_num3)
{
    int r = str_is_alpha_num("6");

    cr_assert_eq(r, 0);
}

Test(str_is_alpha_num, test_str_is_alpha_num4)
{
    int r = str_is_alpha_num("A");

    cr_assert_eq(r, 0);
}

Test(str_is_alpha_num, test_str_is_alpha_num5)
{
    int r = str_is_alpha_num("@");

    cr_assert_eq(r, 1);
}

Test(str_is_alpha_num, test_str_is_alpha_num6)
{
    int r = str_is_alpha_num("[");

    cr_assert_eq(r, 1);
}

Test(str_is_alpha_num, test_str_is_alpha_num7)
{
    int r = str_is_alpha_num("|");

    cr_assert_eq(r, 1);
}