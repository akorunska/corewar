# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 17:30:40 by akorunsk          #+#    #+#              #
#    Updated: 2018/02/21 10:08:22 by akorunsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB_SRC_DIR = ./libsrc

GNL_SRC_DIR = ./gnl_src

SRC = $(shell find $(LIB_SRC_DIR) $(GNL_SRC_DIR) -type f -name "*.c")

OBJ = $(SRC:.c=.o)

INC = -I ../libft.h

FLAGS = -Wall -Wextra -Werror

CFLAGS = -c $(FLAGS)

LIBNAME = libsrc/libft.a

all: $(NAME)

obj: $(OBJ)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o: %.c
		gcc -o $@ $< $(CFLAGS) $(INC)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
