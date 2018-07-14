# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 14:57:47 by igaliuk           #+#    #+#              #
#    Updated: 2018/05/19 17:53:08 by ddenkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

CC = gcc

FLAG = -Wall -Wextra -Werror

SRC = func/ft_add.c \
	func/ft_aff.c \
	func/ft_and.c \
	func/ft_fork.c \
	func/ft_ld.c \
	func/ft_ldi.c \
	func/ft_lfork.c \
	func/ft_live.c \
	func/ft_lld.c \
	func/ft_lldi.c \
	func/ft_or.c \
	func/ft_st.c \
	func/ft_sti.c \
	func/ft_sub.c \
	func/ft_xor.c \
	func/ft_zjmp.c \
	src/ft_arg_convert.c \
	src/ft_atoi_vm.c \
	src/ft_carry_0_or_1.c \
	src/ft_codage_octal.c \
	src/ft_create_processes.c \
	src/ft_error_vm.c \
	src/ft_error2_vm.c \
	src/ft_execution_command.c \
	src/ft_frees_vm.c \
	src/ft_get_args_from_memory.c \
	src/ft_get_set_memory.c \
	src/ft_lstproc_vm.c \
	src/ft_cycle_of_battle.c \
	src/ft_one_cycle_processes.c \
	src/ft_start_battle_with_nc.c \
	src/ft_start_battle_without_nc.c \
	src/ft_output_vm.c \
	src/ft_read_main_arg.c \
	src/ft_read_main_arg_flags.c \
	src/ft_read_write_players.c \
	src/ft_verbosity.c \
	src/init_ncurses.c \
	src/nc_utils.c \
	src/main_vm.c \
	src/op.c

INC = src/vm.h src/op.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "       Compiling project...."
	@$(CC) $(FLAG) libft/libft.a -o $@ $^ -lcurses
	@echo "                                  Done!\n"

%.o: %.c $(INC)
	@$(CC) $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	make clean -C libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C libft
	
	@echo "\n       Objects of project were deleted.\n"
	@echo "       Binary file was deleted.\n"

re: fclean all
