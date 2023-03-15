/*
** EPITECH PROJECT, 2020
** struct garbage
** File description:
** struct garbage
*/

#ifndef __GARBAGE_H__
#define __GARBAGE_H__

typedef struct garbage_collector_s garbage_collector_t;

struct garbage_collector_s
{
    void *ptr;
    garbage_collector_t *next;
};

#endif