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

Test(my_str_to_word_array, test_my_str_to_word_array)
{
    char *str = strdup("hello hello");
    char **tab = my_str_to_word_array(str, " ");

    cr_assert_not_null(tab);
}