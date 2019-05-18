/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"

int cnt_wrd(char *str, char *list_char)
{
    int size = 0;

    for (int i = 0; str[i]; i++)
        if (char_in_list(str[i], list_char))
            size++;
    return (size);
}

char **my_str_to_word_array(char *str, char *list_char)
{
    char **result;
    int size = 0;
    int nb = 0;

    if ((result = malloc(sizeof(char *) * (cnt_wrd(str, list_char) + 2))) ==
        NULL)
        return (NULL);
    while (str[size]) {
        while (!char_in_list(str[size], list_char) && str[size])
            size++;
        if ((result[nb] = malloc(sizeof(char) * (size + 1))) == NULL)
            return (NULL);
        result[nb] = my_strncpy(result[nb], str, size);
        while (char_in_list(str[size], list_char) && str[size])
            size++;
        str += size;
        size = 0;
        nb++;
    }
    result[nb] = NULL;
    return (result);
}