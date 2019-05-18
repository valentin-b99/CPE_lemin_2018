/*
** EPITECH PROJECT, 2018
** convert_to_base
** File description:
** convert_to_base
*/

#include "../../../include/my.h"
#include "include/my_printf.h"
#include <stdlib.h>

char int_to_base(long nb, char *str_base)
{
    int i = 0;

    while (i < nb)
        i++;
    return (str_base[i]);
}

char *convert_to_base(long nb, char *str_base)
{
    int base = my_strlen(str_base);
    char *result = "";
    char *tmp;

    if (nb < 0)
        nb = -nb;
    while (nb > 0) {
        tmp = malloc(sizeof(char) * my_strlen(result));
        my_strcpy(tmp, result);
        result = malloc(sizeof(char) * (my_strlen(result) + 1));
        my_strcpy(result, tmp);
        result[my_strlen(result)] = int_to_base(nb % base, str_base);
        nb = nb / base;
    }
    tmp = malloc(sizeof(char) * my_strlen(result));
    my_strcpy(tmp, result);
    result = malloc(sizeof(char) * (my_strlen(result) + 1));
    my_strcpy(result, tmp);
    result[my_strlen(result)] = 0;
    return (my_revstr(result));
}