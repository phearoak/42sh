/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** hey movement
*/

#include <minishell.h>
#include <my.h>

int end_key_ter(int key, int *pos, int max)
{
    if (key == 70 || key == 5) {
        while (*pos < max) {
            (*pos)++;
            cursorforward(1);
        }
        return (1);
    }
    if (key == 72 || key == 1) {
        while (*pos > 0) {
            (*pos)--;
            cursorbackward(1);
        }
        return (1);
    }
    return (0);
}