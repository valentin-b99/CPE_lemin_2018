/*
** EPITECH PROJECT, 2018
** p_func_bases
** File description:
** functions of printf (hexa, bin, oct...)
*/

#include "../../../include/my.h"
#include "include/my_printf.h"

int p_hex(va_list args, struct input_flags flags)
{
    char *str = convert_to_base(va_arg(args, long), "0123456789abcdef");

    return (p_display(str, flags, 7));
}

int p_chex(va_list args, struct input_flags flags)
{
    char *str = convert_to_base(va_arg(args, long), "0123456789ABCDEF");

    return (p_display(str, flags, 8));
}

int p_oct(va_list args, struct input_flags flags)
{
    char *str = convert_to_base(va_arg(args, long), "01234567");

    return (p_display(str, flags, 6));
}

int p_bin(va_list args, struct input_flags flags)
{
    char *str = convert_to_base(va_arg(args, long), "01");

    return (p_display(str, flags, 6));
}