NAME = ../corewar
CC = gcc
FLG = -Wall -Wextra -Werror
LIBFT = -L ./libft -lft -lcurses
LIB = ../libft.a
INC = src/op.h src/vm.h
SRC = src/op.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)

%.o: %.c $(INC)
	@$(CC) $(FLG) -o $@ -c $<
	@echo "VM done"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "VM annihilated"

re: fclean all

.PHONY: clean fclean all re