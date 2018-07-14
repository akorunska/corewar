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

NAME	=	aida
RM		=   rm -f

VM_PATH	= ./vm
ASM_PATH	= ./asm_dir

all:	$(NAME)

$(NAME):
	@make -C $(VM_PATH)
	@make -C $(ASM_PATH)

clean:
	@make -C $(VM_PATH) clean
	@make -C $(ASM_PATH) clean

fclean:	clean
	@make -C $(VM_PATH) fclean
	@make -C $(ASM_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re