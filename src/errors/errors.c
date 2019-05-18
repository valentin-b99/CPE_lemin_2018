/*
** EPITECH PROJECT, 2019
** errors
** File description:
** errors
*/

#include "../../include/lemin.h"

int detect_ten(char *str)
{
    int com = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '#')
            com = 1;
        if (str[i] == '-' && !com)
            return (1);
    }
    return (0);
}

int errors_rooms(char **file, int **cnt_sproom, int *i,
list_rooms_t *list_rooms)
{
    if (test_special_rooms(file, cnt_sproom, i, list_rooms)) {
        return (1);
    } else if (file[*i] && !detect_ten(file[*i]) && file[*i][0] != '#') {
        if (test_format_salle(file[*i], list_rooms, 0))
            return (1);
    }
    if (file[*i] && !detect_ten(file[*i]))
        *i += 1;
    return (0);
}

int main_ants_errors(char **file, ant_t **ants, int i)
{
    my_putstr("#number_of_ants\n");
    if (!file[i][0] || !my_str_isnum(my_str_to_word_array(file[i], " ")[0]) ||
        (my_arraylen(my_str_to_word_array(file[i], " ")) > 1 &&
        my_str_to_word_array(file[i], " ")[1][0] != '#') ||
        my_getnbr(file[i]) < 1)
        return (1);
    my_printf("%d\n", my_getnbr(file[i]));
    *ants = malloc(sizeof(ant_t) * (my_getnbr(file[i]) + 1));
    (*ants)[my_getnbr(file[i])].name = 0;
    for (int j = 0; j < my_getnbr(file[i]); j++) {
        (*ants)[j].name = j + 1;
        (*ants)[j].curent_room = NULL;
    }
    return (0);
}

int main_rooms_errors(char **file, list_rooms_t *list_rooms, int *i,
int **cnt_sproom)
{
    my_putstr("#rooms\n");
    while (file[*i] && *i < my_arraylen(file) && !detect_ten(file[*i]))
        if (errors_rooms(file, cnt_sproom, i, list_rooms))
            return (1);
    if ((*cnt_sproom)[0] != 1 || (*cnt_sproom)[1] != 1)
        return (1);
    return (0);
}

int main_errors(char **file, list_rooms_t *list_rooms, ant_t **ants)
{
    int i = 0;
    int *cnt_sproom = malloc(sizeof(int) * 2);

    cnt_sproom[0] = 0;
    cnt_sproom[1] = 0;
    if (!file[0])
        return (1);
    while (file[i][0] == '#')
        i++;
    if (main_ants_errors(file, ants, i))
        return (1);
    i++;
    if (main_rooms_errors(file, list_rooms, &i, &cnt_sproom))
        return (1);
    free(cnt_sproom);
    return (error_tunnels(list_rooms, file, &i));
}