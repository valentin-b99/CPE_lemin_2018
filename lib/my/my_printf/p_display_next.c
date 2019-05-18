/*
** EPITECH PROJECT, 2018
** p_display_next
** File description:
** p_display_next
*/

#include "../../../include/my.h"
#include "include/my_printf.h"

int p_display_zero_next(char *str, int isint, struct input_flags flags)
{
    int len = 0;

    if (flags.sharp && isint >= 7) {
        for (int j = 0; j < flags.z_width - my_strlen(str) - flags.space - 2;
            j++)
            len += write(1, "0", 1);
    } else {
        for (int j = 0; j < flags.z_width - my_strlen(str) - flags.space; j++)
            len += write(1, "0", 1);
    }
    return (0);
}

int p_display_space_swmcw(char *str, int isint, int width,
struct input_flags flags)
{
    int len = 0;

    if ((flags.s_width || flags.z_width) && flags.c_width &&
    isint && isint != 5) {
        for (int j = 0; j < width - flags.c_width; j++)
            len += write(1, " ", 1);
    } else {
        for (int j = 0; j < width - my_strlen(str); j++)
            len += write(1, " ", 1);
    }
    return (len);
}

int p_display_space_next(char *str, int isint, int width,
struct input_flags flags)
{
    int len = 0;

    if (isint == 6 && flags.sharp) {
        for (int j = 0; j < width - my_strlen(str) - 1; j++)
            len += write(1, " ", 1);
    } else if (isint >= 7 && flags.sharp) {
        for (int j = 0; j < width - my_strlen(str) - 2; j++)
            len += write(1, " ", 1);
    } else {
        len += p_display_space_swmcw(str, isint, width, flags);
    }
    return (len);
}

int p_display_next(char *str, struct input_flags flags, int isint)
{
    int len = 0;

    len += p_display_zero(str, isint, flags);
    len += p_display_nstr(str, isint, flags);
    len += p_display_float(str, isint, flags);
    if (isint && isint != 2 && isint != 5 && flags.z_width > my_strlen(str) &&
        str[0] == '-')
        len += write(1, str + 1, my_strlen(str + 1));
    else if ((!flags.c_width && isint != 2) || isint == 1 || isint > 5)
        len += write(1, str, my_strlen(str));
    if (isint >= 7)
        isint = 9;
    len += p_display_space(str, isint, -flags.s_width, flags);
    return (0);
}