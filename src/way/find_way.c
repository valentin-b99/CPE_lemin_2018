/*
** EPITECH PROJECT, 2019
** find_way
** File description:
** find_way
*/

#include "../../include/lemin.h"

int room_empty(ant_t *ants, room_t *room)
{
    for (int i = 0; ants[i].name != 0; i++) {
        if (ants[i].curent_room == room)
            return (0);
    }
    return (1);
}

void find_way_link_space(int *end_first)
{
    if (!end_first[1])
        write(1, " ", 1);
    else
        end_first[1] = 0;
}

void find_way_link(int *end_first, link_t *link_tmp, ant_t *ants, int i)
{
    while (link_tmp) {
        if (link_tmp->room->way_pound < ants[i].curent_room->way_pound &&
        (room_empty(ants, link_tmp->room) ||
        link_tmp->room->type == 2)) {
            ants[i].curent_room = link_tmp->room;
            find_way_link_space(end_first);
            my_printf("P%d-%s", ants[i].name, ants[i].curent_room->name);
            end_first[0] = 1;
        }
        link_tmp = link_tmp->next;
    }
}

void find_way(list_rooms_t *list_rooms, ant_t *ants)
{
    room_t *room_tmp;
    room_t *room_end;
    link_t *link_tmp;
    int end_first[2] = {1, 1};

    for (int i = 0; end_first[0] || ants[i].name != 0; i++) {
        if (ants[i].name == 0) {
            write(1, "\n", 1);
            end_first[0] = 0;
            end_first[1] = 1;
            i = 0;
        }
        link_tmp = ants[i].curent_room->links->first;
        find_way_link(end_first, link_tmp, ants, i);
    }
}