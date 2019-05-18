/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include "../../../include/my.h"
#include "include/my_printf.h"
#include "include/struct.h"

int test_is_format_char(char c)
{
    if (c == ' ')
        return (1);
    if (c == '\'')
        return (1);
    if (c == '+')
        return (1);
    if (c == '-')
        return (1);
    if (c == '.')
        return (1);
    if (c == '#')
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

struct input_flags get_flags(char *form, int *i)
{
    struct input_flags flags = {0};

    while (test_is_format_char(form[*i])) {
        if (form[*i] == '+')
            flags.add = 1;
        if (form[*i] == ' ')
            flags.space = 1;
        if (form[*i] == '#')
            flags.sharp = 1;
        if (((form[*i] >= '1' && form[*i] <= '9') || form[*i] == '-') &&
            flags.s_width == 0)
            flags.s_width = ptf_getnbr(form, i);
        if (form[*i] == '0' && flags.z_width == 0)
            flags.z_width = ptf_getnbr(form, i);
        if (form[*i] == '.' && flags.c_width == 0)
            flags.c_width = ptf_getnbr(form, i);
        *i += 1;
    }
    return (flags);
}

int get_input(char *form, va_list args, int *i)
{
    int init_i = *i;
    struct input_flags flags;

    if (*i >= my_strlen(form) - 1)
        return (write(1, "%", 1));
    *i += 1;
    flags = get_flags(form, i);
    for (int j = 0; j < 14; j++)
        if (form[*i] == s_funct[j].str[0])
            return (s_funct[j].func(args, flags));
    for (int j = 14; j < 18; j++) {
        if (form[*i] == s_funct[j].str[0] &&
        form[*i + 1] == s_funct[j].str[1]) {
            *i += 1;
            return (s_funct[j].func(args, flags));
        }
    }
    *i = init_i;
    return (write(1, "%", 1));
}

int my_printf(char *form, ...)
{
    int i = 0;
    int str_len = 0;
    va_list args;

    va_start(args, form);
    while (form[i] != 0) {
        if (form[i] == '%')
            str_len += get_input(form, args, &i);
        else
            str_len += write(1, &form[i], 1);
        i++;
    }
    va_end(args);
    return (str_len);
}