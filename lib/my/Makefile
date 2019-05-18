##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile
##

NAME	= libmy.a

CC	= gcc

RM	= rm -f

SRCS	= ./char_in_list.c \
	  ./concat_params.c \
	  ./get_next_line.c \
	  ./how_many_int.c \
	  ./int_to_char.c \
	  ./my_arraylen.c \
	  ./my_charisalpha.c \
	  ./my_charisnum.c \
	  ./my_compute_power_rec.c \
	  ./my_compute_square_root.c \
	  ./my_find_prime_sup.c \
	  ./my_getnbr.c \
	  ./my_inserstrcat.c \
	  ./my_is_prime.c \
	  ./my_isneg.c \
	  ./my_printf/convert_to_base.c \
	  ./my_printf/int_to_char.c \
	  ./my_printf/my_printf.c \
	  ./my_printf/p_display.c \
	  ./my_printf/p_display_next.c \
	  ./my_printf/p_func_bases.c \
	  ./my_printf/p_func_int.c \
	  ./my_printf/p_func_str.c \
	  ./my_printf/p_func_str2.c \
	  ./my_printf/ptf_getnbr.c \
	  ./my_putchar.c \
	  ./my_putnbr.c \
	  ./my_putstr.c \
	  ./my_revstr.c \
	  ./my_sort_int_array.c \
	  ./my_str_isalpha.c \
	  ./my_str_islower.c \
	  ./my_str_isnum.c \
	  ./my_str_to_word_array.c \
	  ./my_str_isnum_with_add_and_sub.c \
	  ./my_strcapitalize.c \
	  ./my_strcat_malloc.c \
	  ./my_strcat.c \
	  ./my_strcmp.c \
	  ./my_strcpy.c \
	  ./my_strdup.c \
	  ./my_strlen.c \
	  ./my_strlowcase.c \
	  ./my_strncat.c \
	  ./my_strncmp.c \
	  ./my_strncpy.c \
	  ./my_strupcase.c \
	  ./my_swap.c \
	  ./my_tablen.c

OBJS	= ./char_in_list.o \
	  ./concat_params.o \
	  ./get_next_line.o \
	  ./how_many_int.o \
	  ./int_to_char.o \
	  ./my_arraylen.o \
	  ./my_charisalpha.o \
	  ./my_charisnum.o \
	  ./my_compute_power_rec.o \
	  ./my_compute_square_root.o \
	  ./my_find_prime_sup.o \
	  ./my_getnbr.o \
	  ./my_inserstrcat.o \
	  ./my_is_prime.o \
	  ./my_isneg.o \
	  ./convert_to_base.o \
	  ./int_to_char.o \
	  ./my_printf.o \
	  ./p_display.o \
	  ./p_display_next.o \
	  ./p_func_bases.o \
	  ./p_func_int.o \
	  ./p_func_str.o \
	  ./p_func_str2.o \
	  ./ptf_getnbr.o \
	  ./my_putchar.o \
	  ./my_putnbr.o \
	  ./my_putstr.o \
	  ./my_revstr.o \
	  ./my_sort_int_array.o \
	  ./my_str_isalpha.o \
	  ./my_str_islower.o \
	  ./my_str_isnum.o \
	  ./my_str_to_word_array.o \
	  ./my_str_isnum_with_add_and_sub.o \
	  ./my_strcapitalize.o \
	  ./my_strcat_malloc.o \
	  ./my_strcat.o \
	  ./my_strcmp.o \
	  ./my_strcpy.o \
	  ./my_strdup.o \
	  ./my_strlen.o \
	  ./my_strlowcase.o \
	  ./my_strncat.o \
	  ./my_strncmp.o \
	  ./my_strncpy.o \
	  ./my_strupcase.o \
	  ./my_swap.o \
	  ./my_tablen.o

CFLAGS = -I ./my_printf/include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME):
	 $(CC) -c $(SRCS)
	 ar rc $(NAME) $(OBJS)
	 make clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
