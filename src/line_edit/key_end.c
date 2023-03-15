/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** hey movement
*/

#include <minishell.h>
#include <my.h>

int end_key(int key, int *pos, int max)
{
    if (key == 360 || key == 5) {
        while (*pos < max) {
            (*pos)++;
            cursorforward(1);
        }
        return (1);
    }
    if (key == 262 || key == 1) {
        while (*pos > 0) {
            (*pos)--;
            cursorbackward(1);
        }
        return (1);
    }
    return (0);
}