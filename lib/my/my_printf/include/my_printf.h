/*
** EPITECH PROJECT, 2018
** my
** File description:
** my
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

struct input_flags
{
    int add;/* '%+d' */
    int space;/* '% d' */
    int sharp;/* '%#d' */
    int s_width;/* '%10s' / '%-10s' */
    int z_width;/* '%02d' */
    int c_width;/* '%.5s' */
};

struct input_funct
{
    char *str;
    int (*func)(va_list args, struct input_flags);
};

int test_is_format_char(char);
struct input_flags get_flags(char *, int *);
int get_input(char *, va_list args, int *);

char int_to_base(long, char *);
char *convert_to_base(long, char *);
char *int_to_char(int);
char *lint_to_char(long);
int ptf_getnbr(char const *, int *);

int p_int(va_list args, struct input_flags);
int p_char(va_list args, struct input_flags);
int p_str(va_list args, struct input_flags);
int p_sstr(va_list args, struct input_flags);
void p_sstr_malloc(char **, char *);
void p_sstr_addzero(char **, char *);
int p_ptr(va_list args, struct input_flags);
int p_hex(va_list args, struct input_flags);
int p_chex(va_list args, struct input_flags);
int p_intn(va_list args, struct input_flags);
int p_oct(va_list args, struct input_flags);
int p_bin(va_list args, struct input_flags);
int p_per(va_list args, struct input_flags);
int p_float(va_list args, struct input_flags);
int p_error(va_list args, struct input_flags);

int p_lint(va_list args, struct input_flags);
int p_sint(va_list args, struct input_flags);

int p_display(char *, struct input_flags, int);
int p_display_next(char *, struct input_flags, int);
int p_display_nstr(char *, int, struct input_flags);
int p_display_float(char *, int, struct input_flags);
int p_display_zero(char *, int, struct input_flags);
int p_display_zero_next(char *, int, struct input_flags);
int p_display_space(char *, int, int, struct input_flags);
int p_display_space_next(char *, int, int, struct input_flags);
int p_display_space_swmcw(char *, int, int, struct input_flags);
int p_display_nstr(char *, int, struct input_flags);

#endif /* !MY_PRINTF_H_ */
