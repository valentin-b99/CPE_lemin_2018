/*
** EPITECH PROJECT, 2018
** my_strcat_malloc
** File description:
** my_strcat_malloc
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat_malloc(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    my_strcpy(tmp, dest);
    dest = tmp;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
