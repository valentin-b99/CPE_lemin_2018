/*
** EPITECH PROJECT, 2019
** init_way
** File description:
** init_way
*/

#include "../../include/lemin.h"

room_t *init_init_way(room_t *room_tmp, ant_t *ants)
{
    room_t *room_start;
    while (room_tmp) {
        if (room_tmp->type == 1)
            room_start = room_tmp;
        room_tmp = room_tmp->next;
    }

    for (int i = 0; ants[i].name != 0; i++) {
        ants[i].curent_room = room_start;
    }
    return (room_start);
}

void init_way_link(link_t *link_tmp, room_t *room_tmp, int *impossible_way)
{
    while (link_tmp) {
        if (link_tmp->room->way_pound == -1) {
            link_tmp->room->way_pound = room_tmp->way_pound + 1;
            *impossible_way = 0;
        }
        link_tmp = link_tmp->next;
    }
}

int count_ant(ant_t *ants)
{
    int i = 0;
    while (ants[i++].name != 0);
    return (i - 1);
}

int init_way(list_rooms_t *list_rooms, ant_t *ants)
{
    room_t *room_tmp = list_rooms->first;
    link_t *link_tmp;
    room_t *room_start = init_init_way(room_tmp, ants);
    int impossible_way = 1;

    room_start->ant = count_ant(ants);
    room_tmp = list_rooms->first;
    while (room_start->way_pound == -1) {
        if (room_tmp->way_pound != -1)
            link_tmp = room_tmp->links->first;
        init_way_link(link_tmp, room_tmp, &impossible_way);
        room_tmp = room_tmp->next;
        if (impossible_way && !room_tmp)
            return (84);
        if (!room_tmp) {
            room_tmp = list_rooms->first;
            impossible_way = 1;
        }
    }
    return (0);
}