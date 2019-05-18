/*
** EPITECH PROJECT, 2019
** ptf_getnbr
** File description:
** ptf_getnbr
*/

#include "../../../include/my.h"
#include "include/my_printf.h"

int ptf_getnbr(char const *str, int *i)
{
    long nbr = 0;
    int is_neg = 1;

    while (str[*i] && !my_charisnum(str[*i])) {
        if (str[*i] == '-')
            is_neg *= -1;
        *i += 1;
    }
    while (str[*i] && my_charisnum(str[*i])) {
        nbr = nbr * 10 + (str[*i] - 48);
        *i += 1;
    }
    nbr *= is_neg;
    if (nbr < -2147483648 || nbr > 2147483647)
        return (0);
    return (nbr);
}