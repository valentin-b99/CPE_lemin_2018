/*
** EPITECH PROJECT, 2018
** p_func_str2
** File description:
** p_func_str2
*/

#include "../../../include/my.h"
#include "include/my_printf.h"
#include "include/errors.h"

int p_ptr(va_list args, struct input_flags flags)
{
    char *str = malloc(sizeof(char) * 14);
    char *pstr = convert_to_base(va_arg(args, long), "0123456789abcdef");

    my_strcat(str, "0x");
    my_strcat(str, pstr);
    return (p_display(str, flags, 1));
}

int p_per(va_list args, struct input_flags flags)
{
    return (write(1, "%", 1));
}

int p_error(va_list args, struct input_flags flags)
{
    char *str;
    int i = 0;

    while (i != errno && i < 134)
        i++;
    return (p_display(errors[i].msg, flags, 0));
}