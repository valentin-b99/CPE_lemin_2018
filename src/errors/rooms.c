/*
** EPITECH PROJECT, 2019
** rooms.c
** File description:
** rooms
*/

#include "../../include/lemin.h"

int room_coords_same(list_rooms_t *list_rooms, int *coords)
{
    room_t *room = list_rooms->first;

    while (room) {
        if (room->coords[0] == coords[0] && room->coords[1] == coords[1])
            return (1);
        room = room->next;
    }
    return (0);
}

int display_add_room(char **array_str, list_rooms_t *list_rooms, int type)
{
    int *coords = malloc(sizeof(int) * 2);

    if (room_exist(array_str[0], list_rooms))
        return (1);
    coords[0] = my_getnbr(array_str[1]);
    coords[1] = my_getnbr(array_str[2]);
    if (room_coords_same(list_rooms, coords))
        return (1);
    add_room(list_rooms, array_str[0], type, coords);
    my_printf("%s %s %s\n", array_str[0], array_str[1], array_str[2]);
    return (0);
}

int test_format_salle(char *str, list_rooms_t *list_rooms, int type)
{
    char **array_str = my_str_to_word_array(str, " ");
    int com = 0;
    int nb_param = 1;

    if (!name_room_is_good(array_str[0]))
        return (1);
    for (int i = 1; array_str[i] && !com; i++) {
        if (array_str[i][0] == '#')
            com = 1;
        if (!com && !my_str_isnum(array_str[i]))
            return (1);
        else if (!com)
            nb_param += 1;
    }
    if (nb_param != 3)
        return (1);
    if (display_add_room(array_str, list_rooms, type))
        return (1);
    return (0);
}

int test_special_rooms_start(char **file, int **cnt_sproom, int *i,
list_rooms_t *list_room)
{
    if (file[*i] && !my_strcmp(file[*i], "##start")) {
        while (my_strncmp(file[*i], "#", 1))
            *i += 1;
        my_putstr("##start\n");
        if (test_format_salle(file[*i], list_room, 1))
            return (1);
        (*cnt_sproom)[0] += 1;
        *i += 1;
    }
    return (0);
}

int test_special_rooms(char **file, int **cnt_sproom, int *i,
list_rooms_t *list_room)
{
    if (test_special_rooms_start(file, cnt_sproom, i, list_room))
        return (1);
    if (file[*i] && !my_strcmp(file[*i], "##end")) {
        while (my_strncmp(file[*i], "#", 1))
            *i += 1;
        my_putstr("##end\n");
        if (test_format_salle(file[*i], list_room, 2))
            return (1);
        (*cnt_sproom)[1] += 1;
        *i += 1;
    }
    if (test_special_rooms_start(file, cnt_sproom, i, list_room))
        return (1);
    return (0);
}