/*
** EPITECH PROJECT, 2019
** lib.c
** File description:
** lib
*/

#include "../include/lemin.h"

char *str_char_cp(char *str, char c)
{
    int i = -1;
    char *cp_str;
    int j = 0;

    while (str[++i] != c && str[i]);
    cp_str = malloc(sizeof(char) * i + 1);
    while (str[j] != c && str[j]) {
        cp_str[j] = str[j];
        j++;
    }
    cp_str[j] = '\0';
    return (cp_str);
}

char *str_cp_char(char *str, char c)
{
    int i = -1;
    char *cp_str;
    int j = 0;

    while (str[++i] != c && str[i]);
    while (str[++i] != '\0')
        j++;
    cp_str = malloc(sizeof(char) * j + 1);
    i = i - j;
    j = 0;
    while (str[i] != '\0') {
        cp_str[j] = str[i];
        j++;
        i++;
    }
    cp_str[j] = '\0';
    return (cp_str);
}

int my_strlen_char(char *str, char c)
{
    int i = 0;

    while (str[i] && str[i] != c)
        i++;
    return (i);
}

int name_room_is_good(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] < 65 || str[i] > 90) &&
            (str[i] < 97 || str[i] > 122) &&
            (str[i] < 48 || str[i] > 57) &&
            str[i] != '_')
            return (0);
    }
    return (1);
}

int room_exist(char *name, list_rooms_t *list_rooms)
{
    room_t *room = list_rooms->first;

    while (room) {
        if (!my_strcmp(name, room->name))
            return (1);
        room = room->next;
    }
    return (0);
}