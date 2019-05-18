/*
** EPITECH PROJECT, 2018
** p_display
** File description:
** p_display
*/

#include "../../../include/my.h"
#include "include/my_printf.h"

int p_display_float(char *str, int isint, struct input_flags flags)
{
    int i = 0;
    int len = 0;

    if (isint == 2 && !flags.c_width) {
        len += write(1, str, my_strlen(int_to_char(ptf_getnbr(str, &i))) + 7);
    } else if (isint == 2 && flags.c_width) {
        len += write(1, str, my_strlen(int_to_char(ptf_getnbr(str, &i))) + 1 +
        flags.c_width);
    }
    if (flags.c_width && isint && isint != 2 && isint != 5) {
        for (int j = 0; j < flags.c_width - my_strlen(str); j++)
            len += write(1, "0", 1);
    }
    return (len);
}

int p_display_nstr(char *str, int isint, struct input_flags flags)
{
    int len = 0;

    if (flags.c_width > my_strlen(str) && (!isint || isint == 5))
        len+= write(1, str, my_strlen(str));
    else if (flags.c_width && !isint)
        len+= write(1, str, flags.c_width);
    return (len);
}

int p_display_zero(char *str, int isint, struct input_flags flags)
{
    int len = 0;

    if (flags.sharp && isint == 6 && !flags.z_width)
        len += write(1, "0", 1);
    if (flags.z_width - my_strlen(str) > 0 && isint &&
    (isint < 5 || isint >= 6) && !flags.c_width) {
        if (str[0] == '-')
            len += write(1, "-", 1);
        len += p_display_zero_next(str, isint, flags);
    } else if (flags.z_width - my_strlen(str) > 0 && (!isint || isint == 5 ||
    (isint >= 6 && !flags.sharp))) {
        p_display_space(str, isint, flags.z_width, flags);
        return (len);
    }
    if (flags.z_width && flags.c_width && isint != 5 && isint < 7) {
        for (int j = 0; j < flags.z_width - flags.c_width; j++)
            len += write(1, " ", 1);
    }
    return (len);
}

int p_display_space(char *str, int isint, int width, struct input_flags flags)
{
    int len = 0;

    if (flags.z_width && flags.c_width && flags.sharp && isint >= 7
    && isint != 9) {
        for (int j = 0; j < flags.z_width - flags.c_width - 2; j++)
            len += write(1, " ", 1);
    }
    if ((width - my_strlen(str) > 0 && width - flags.c_width > 0) ||
    isint <= 5) {
        len += p_display_space_next(str, isint, width, flags);
    }
    return (len);
}

int p_display(char *str, struct input_flags flags, int isint)
{
    char add_str = 0;
    int len = 0;

    if (flags.space && isint && isint < 5 && !flags.s_width)
        add_str = ' ';
    if (flags.add && isint && isint < 5 && str[0] != '-')
        add_str = '+';
    if (add_str != 0)
        len += write(1, &add_str, 1);
    len += p_display_space(str, isint, flags.s_width, flags);
    if (flags.sharp && isint == 7)
        len += write(1, "0x", 2);
    if (flags.sharp && isint == 8)
        len += write(1, "0X", 2);
    len += p_display_next(str, flags, isint);
    return (len);
}