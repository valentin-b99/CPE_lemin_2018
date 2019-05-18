/*
** EPITECH PROJECT, 2019
** init_rooms.c
** File description:
** init_rooms
*/

#include "../../include/lemin.h"

void init_list_rooms(list_rooms_t *list)
{
    list->nb = 0;
    list->first = NULL;
}

void init_list_links(list_links_t *list)
{
    list->nb = 0;
    list->first = NULL;
}