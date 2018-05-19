NAME = whatever

LIB = ./libft
LIBFT = -L ./libft -lft
VM = ./vm
ASM = ./asm_dir

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@make -C $(VM)
#	@make -C $(ASM)

clean:
	@make -C $(LIB) clean
	@make -C $(VM) clean
#	@make -C $(ASM) clean

fclean:
	@make -C $(LIB) fclean
	@make -C $(VM) fclean
#	@make -C $(ASM) fclean

re: fclean all

.PHONY: all clean fclean re
