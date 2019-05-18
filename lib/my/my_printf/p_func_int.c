/*
** EPITECH PROJECT, 2018
** p_func_int
** File description:
** functions of printf (int)
*/

#include "../../../include/my.h"
#include "include/my_printf.h"

int p_int(va_list args, struct input_flags flags)
{
    char *nb = int_to_char(va_arg(args, int));

    return (p_display(nb, flags, 1));
}

int p_intn(va_list args, struct input_flags flags)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *result = malloc(sizeof(char) * 11);
    int i = 0;

    if (nb == 0 || nb < 0)
        return (write(1, "0", 1));
    while (nb != 0) {
        result[i] = (nb % 10) + 48;
        nb = nb /10;
        i++;
    }
    result[i] = '\0';
    result = my_revstr(result);
    return (p_display(result, flags, 1));
}

int p_lint(va_list args, struct input_flags flags)
{
    char *nb = lint_to_char(va_arg(args, long));

    return (p_display(nb, flags, 1));
}

int p_float(va_list args, struct input_flags flags)
{
    float str = va_arg(args, double);
    long str2 = str;
    char *nb = int_to_char(str2);
    char *nnb;

    my_strcat(nb, ".");
    str = str - str2;
    if (str < 0)
        str = -str;
    for (int i = 0; i < 7; i++)
        str = str * 10;
    str2 = str;
    nnb = lint_to_char(str2);
    for (int i = 0; i <= my_strlen(nb) + 5 && nnb[i] != 0; i++)
        my_strcat(nb, &nnb[i]);
    return (p_display(nb, flags, 2));
}

int p_sint(va_list args, struct input_flags flags)
{
    int i = va_arg(args, int);
    short j = i;
    char *nb = int_to_char(j);

    return (p_display(nb, flags, 1));
}
