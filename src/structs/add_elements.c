/*
** EPITECH PROJECT, 2019
** add_elements.c
** File description:
** add_elements
*/

#include "../../include/lemin.h"

void add_room(list_rooms_t *list, char *name, int type, int *coords)
{
    room_t *room = malloc(sizeof(*room));

    room->name = malloc(sizeof(char) * (my_strlen_char(name, ' ') + 1));
    room->name = my_strncpy(room->name, name, my_strlen_char(name, ' '));
    room->type = type;
    room->coords = malloc(sizeof(int) * 2);
    room->coords = coords;
    room->ant = 0;
    room->way_pound = -1;
    if (type == 2)
        room->way_pound = 0;
    room->links = malloc(sizeof(list_links_t));
    init_list_links(room->links);
    room->next = list->first;
    list->nb += 1;
    list->first = room;
}

void add_link(list_links_t *list, room_t *room)
{
    link_t *link = malloc(sizeof(*link));

    link->room = room;
    link->next = list->first;
    list->nb += 1;
    list->first = link;
}

void add_link_to_room(list_rooms_t *list_rooms, char *str_from, char *str_to)
{
    room_t *room_tmp = list_rooms->first;
    room_t *room_from = NULL;
    room_t *room_to = NULL;

    while (room_tmp) {
        if (!my_strcmp(room_tmp->name, str_from))
            room_from = room_tmp;
        else if (!my_strcmp(room_tmp->name, str_to))
            room_to = room_tmp;
        room_tmp = room_tmp->next;
    }
    if (room_from && room_to)
        add_link(room_from->links, room_to);
}