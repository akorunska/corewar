# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/05/22 12:21:33 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

LIB = libftprintf.a

SRCS =	main.c ft_asm_read_file.c ft_asm_regex_add.c ft_asm_regex_aff.c \
		ft_asm_regex_and.c ft_asm_regex_champ_comment.c ft_asm_regex_champ_name.c \
		ft_asm_regex_empty_line.c ft_asm_regex_fork.c ft_asm_regex_ld.c \
		ft_asm_regex_ldi.c ft_asm_regex_lfork.c ft_asm_regex_live.c \
		ft_asm_regex_lld.c ft_asm_regex_lldi.c ft_asm_regex_or.c ft_asm_regex_st.c \
		ft_asm_regex_sti.c ft_asm_regex_sub.c ft_asm_regex_xor.c ft_asm_regex_zjmp.c \
		ft_asm_skip_symb.c ft_asm_valid.c \
		ab_arr_list/ft_ab_arr_list.c \
		array_list_access.c array_list.c asm_parse.c command_info.c command_to_bytecode.c \
		file_to_bytecode.c parse_command.c parse_element.c \
		ft_asm_regex_is_duplicated_label.c ft_asm_labels_matching.c ft_asm_clean_params.c \
		ft_asm_print_error.c ft_asm_regex_aff_2.c ft_asm_finish_success.c \
		ft_asm_regex_live_2.c ft_asm_regex_ld_2.c ft_asm_regex_st_2.c ft_asm_regex_add_2.c \
		ft_asm_regex_and_2.c ft_asm_regex_and_3.c ft_asm_regex_ldi_2.c ft_asm_regex_ldi_3.c \
		ft_asm_regex_sti_2.c ft_asm_regex_sti_3.c
		

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADERS = *.h

all: $(NAME)

%.o : %.c
	@gcc -g -I. -I./libftprintf -I./ab_arr_list $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJECTS) $(HEADERS)
	@gcc -g -o $@ -I. -I./libftprintf $(OBJECTS) $(LIB)
	@echo "\033[1;32mASM is ready\033[0m"

$(LIB):
	@make -C ./libftprintf/
	@cp ./libftprintf/libftprintf.a .

clean:
	@make fclean -C ./libftprintf
	@rm -f *.o
	@rm -f ab_arr_list/*.o
	@rm -f libftprintf.a
	@echo "\033[1;32mObject files ASM were removed\033[0m"

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
