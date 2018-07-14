# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 14:55:16 by igaliuk           #+#    #+#              #
#    Updated: 2018/05/06 10:46:13 by igaliuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -Wall -Wextra -Werror

SRC = ft_arrdel.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_checkmapchar.c \
	ft_checkmapsize.c \
	ft_del.c \
	ft_intlen.c \
	ft_intsort.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isblank.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_lstadd.c \
	ft_lstaddback.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstdeloneany.c \
	ft_lstiter.c \
	ft_lstlen.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lsttostr.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_ordernum_base.c \
	ft_ordernum.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strisdigit.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strpbrk.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_swap.c \
	ft_swaps_bits_int.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_min.c \
	ft_max.c \
	get_next_line.c
SRC2 = ft_printf/ft_aaff.c \
	ft_printf/ft_colors.c \
	ft_printf/ft_first.c \
	ft_printf/ft_itoa_base_u.c \
	ft_printf/ft_lsttostrzlo.c \
	ft_printf/ft_ordernum_base_u.c \
	ft_printf/ft_persent.c \
	ft_printf/ft_precision.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printint.c \
	ft_printf/ft_printtype.c \
	ft_printf/ft_second.c \
	ft_printf/ft_specifier.c \
	ft_printf/ft_tofin.c \
	ft_printf/ft_wecha.c \
	ft_printf/ft_writepersent.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): echo1 $(OBJ) $(OBJ2) echo0
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ) $(OBJ2)


fclean: clean

	@echo "\n       Objects of library were deleted.\n"
	@echo "       Library was deleted.\n"
	@rm -f $(NAME)

re: fclean all

echo0:
	@echo "                                  Done!\n"

echo1:
	@echo "\n       Compiling library...."

