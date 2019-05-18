/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "../include/lemin.h"

int main(void)
{
    char **file = my_str_to_word_array(get_next_line(0), "\n");
    list_rooms_t *list_rooms = malloc(sizeof(list_rooms_t));
    ant_t *ants;

    init_list_rooms(list_rooms);
    if (main_errors(file, list_rooms, &ants))
        return (84);
    my_putstr("#moves\n");
    if (init_way(list_rooms, ants) == 84)
        return (84);
    find_way(list_rooms, ants);
    free(list_rooms);
    return (0);
}