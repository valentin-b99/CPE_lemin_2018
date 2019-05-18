/*
** EPITECH PROJECT, 2018
** p_func_str
** File description:
** functions of printf (c, str, ptr, %)
*/

#include "../../../include/my.h"
#include "include/my_printf.h"

int p_char(va_list args, struct input_flags flags)
{
    char str[2] = {va_arg(args, int), 0};

    return (p_display(str, flags, 5));
}

int p_str(va_list args, struct input_flags flags)
{
    char *str = va_arg(args, char *);

    return (p_display(str, flags, 0));
}

void p_sstr_malloc(char **str, char *add_str)
{
    char *tmp;

    tmp = malloc(sizeof(char) * my_strlen(*str));
    my_strcpy(tmp, *str);
    *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    my_strcpy(*str, tmp);
    my_strcat(*str, add_str);
}

void p_sstr_addzero(char **str, char *xstr)
{
    for (int j = 0; j < 3 - my_strlen(xstr); j++)
        p_sstr_malloc(str, "0");
}

int p_sstr(va_list args, struct input_flags flags)
{
    char *nstr = va_arg(args, char *);
    char *str = "";
    char tmp[2];
    char *xstr;

    for (int i = 0; nstr[i] != 0; i++) {
        if (nstr[i] > 31 && nstr[i] < 127) {
            tmp[0] = nstr[i];
            tmp[1] = 0;
            p_sstr_malloc(&str, tmp);
        } else {
            xstr = convert_to_base(nstr[i], "01234567");
            p_sstr_malloc(&str, "\\");
            p_sstr_addzero(&str, xstr);
            p_sstr_malloc(&str, xstr);
        }
    }
    return (p_display(str, flags, 0));
}