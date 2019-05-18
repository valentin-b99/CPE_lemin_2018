/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    long nbr = 0;
    int is_neg = 1;

    while (str[i] && !my_charisnum(str[i])) {
        if (str[i] == '-')
            is_neg *= -1;
        i++;
    }
    while (str[i] && my_charisnum(str[i])) {
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    nbr *= is_neg;
    if (nbr < -2147483648 || nbr > 2147483647)
        return (0);
    return (nbr);
}
