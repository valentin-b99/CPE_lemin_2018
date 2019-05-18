/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#ifndef PRINTF_STRUCT_H_
#define PRINTF_STRUCT_H_

const struct input_funct s_funct[] =
{
    {"d", &p_int},
    {"i", &p_int},
    {"c", &p_char},
    {"s", &p_str},
    {"S", &p_sstr},
    {"p", &p_ptr},
    {"x", &p_hex},
    {"X", &p_chex},
    {"u", &p_intn},
    {"o", &p_oct},
    {"b", &p_bin},
    {"%", &p_per},
    {"f", &p_float},
    {"m", &p_error},
    {"ld", &p_lint},
    {"li", &p_lint},
    {"hd", &p_sint},
    {"hi", &p_sint}
};

#endif /* !PRINTF_STRUCT_H_ */