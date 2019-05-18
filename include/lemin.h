/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contain all include
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

typedef struct link_s
{
    struct room_s *room;
    struct link_s *next;
} link_t;

typedef struct list_links_s
{
    int nb;
    link_t *first;
} list_links_t;

typedef struct room_s
{
    char *name;
    int type;
    int *coords;
    list_links_t *links;
    struct room_s *next;
    int way_pound;
    int ant;
} room_t;

typedef struct list_rooms_s
{
    int nb;
    room_t *first;
} list_rooms_t;

typedef struct ant_s
{
    int name;
    room_t *curent_room;
    struct ant_s *next;
} ant_t;


/* errors/errors.c */
int detect_ten(char *str);
int errors_rooms(char **file, int **cnt_sproom, int *i,
list_rooms_t *list_rooms);
int main_ants_errors(char **file, ant_t **ants, int i);
int main_rooms_errors(char **file, list_rooms_t *list_rooms, int *i,
int **cnt_sproom);
int main_errors(char **file, list_rooms_t *list_rooms, ant_t **ants);

/* errors/rooms.c */
int room_coords_same(list_rooms_t *list_rooms, int *coords);
int display_add_room(char **array_str, list_rooms_t *list_rooms, int type);
int test_format_salle(char *str, list_rooms_t *list_rooms, int type);
int test_special_rooms_start(char **file, int **cnt_sproom, int *i,
list_rooms_t *list_room);
int test_special_rooms(char **file, int **cnt_sproom, int *i,
list_rooms_t *list_room);

/* errors/tunnels.c */
int verrif_link_exist(list_links_t *links, char *room_to);
int link_exist(list_rooms_t *list_rooms, char *room_from, char *room_to);
int verrif_format_tunnel(char *str, list_rooms_t *list_rooms);
int verrif_line_tunnel(char **file, int *i, list_rooms_t *list_rooms);
int error_tunnels(list_rooms_t *list_rooms, char **file, int *i);

/* structs/initialization.c */
void init_list_rooms(list_rooms_t *list);
void init_list_links(list_links_t *list);

/* structs/add_elements.c */
void add_room(list_rooms_t *list, char *name, int type, int *coords);
void add_link(list_links_t *list, room_t *room);
void add_link_to_room(list_rooms_t *list_rooms, char *str_from, char *str_to);

/* way/find_way.c */
int room_empty(ant_t *ant, room_t *room);
void find_way_link_space(int *end_first);
void find_way_link(int *end_first, link_t *link_tmp, ant_t *ants, int i);
void find_way(list_rooms_t *list_rooms, ant_t *ants);

/* way/init_way.c */
room_t *init_init_way(room_t *room_tmp, ant_t *ant_tmp);
void init_way_link(link_t *link_tmp, room_t *room_tmp, int *impossible_way);
int init_way(list_rooms_t *list_rooms, ant_t *ants);

/* lib.c */
char *str_char_cp(char *str, char c);
char *str_cp_char(char *str, char c);
int my_strlen_char(char *str, char c);
int name_room_is_good(char *str);
int room_exist(char *name, list_rooms_t *list_rooms);

/* main.c */
int my_strlen_char(char *str, char c);

#endif /* !LEMIN_H_ */
