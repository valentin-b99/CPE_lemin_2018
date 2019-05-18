/*
** EPITECH PROJECT, 2019
** tunnels.c
** File description:
** tunnels
*/

#include "../../include/lemin.h"

int verrif_link_exist(list_links_t *links, char *room_to)
{
    link_t *link = links->first;

    while (link) {
        if (!my_strcmp(link->room->name, room_to))
            return (1);
        link = link->next;
    }
    return (0);
}

int link_exist(list_rooms_t *list_rooms, char *room_from, char *room_to)
{
    room_t *room = list_rooms->first;

    while (room) {
        if (!my_strcmp(room_from, room->name) &&
            verrif_link_exist(room->links, room_to))
            return (1);
        room = room->next;
    }
    return (0);
}

int verrif_format_tunnel(char *str, list_rooms_t *list_rooms)
{
    char **arr_str = my_str_to_word_array(str, "-");

    if (my_arraylen(arr_str) != 2)
        return (1);
    if (!name_room_is_good(arr_str[0]) || !name_room_is_good(arr_str[1]))
        return (1);
    if (!room_exist(arr_str[0], list_rooms) ||
        !room_exist(arr_str[1], list_rooms))
        return (1);
    if (!link_exist(list_rooms, arr_str[0], arr_str[1])) {
        my_printf("%s-%s\n", arr_str[0], arr_str[1]);
        add_link_to_room(list_rooms, arr_str[0], arr_str[1]);
        add_link_to_room(list_rooms, arr_str[1], arr_str[0]);
    }
    return (0);
}

int verrif_line_tunnel(char **file, int *i, list_rooms_t *list_rooms)
{
    char **arr_str = my_str_to_word_array(file[*i], " ");

    if (arr_str[0][0] == '#')
        return (0);
    if (my_arraylen(arr_str) > 1 && arr_str[1][0] != '#')
        return (1);
    if (verrif_format_tunnel(arr_str[0], list_rooms))
        return (1);
    return (0);
}

int error_tunnels(list_rooms_t *list_rooms, char **file, int *i)
{
    int tun = *i;

    my_putstr("#tunnels\n");
    while (file[*i]) {
        if (verrif_line_tunnel(file, i, list_rooms))
            return (1);
        *i += 1;
    }
    if (*i == tun)
        return (1);
    return (0);
}