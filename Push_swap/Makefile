# COLORS
BLUE	= \033[0;34m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

NAME	=	push_swap

CC		=	cc
FLAGS	=	-Walls -Werror -Wextra -fsanitize=address -g3

RM		=	rm -rf

FOLDER	=	src/

FILES	=	handle_error.c \
			init_stacks.c \
			indexation.c \
			push_swap.c \
			swap.c \
			rotate.c \
			push.c \
			reverse_rotate.c \
			algo.c \
			test_sort.c \
			simple_sort.c \
		
PRINFT	= 	./ft_printf/libftprintf.a
LIBFT	= 	./libft/libft.a


SRC 	=	$(addprefix $(FOLDER), $(FILES))
OBJ 	=	$(SRC:.c=.o)

all: $(OBJ)
	@$(MAKE) -C ./ft_printf
	@$(MAKE) -C ./libft
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINFT)
	@echo "[$(BLUE)created$(RESET)]: libft.a, libftprintf.a"

clean:
	@$(MAKE) -C ./ft_printf clean
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJ)
	@echo "[$(RED)deleted$(RESET)]: *.o files"

fclean: clean
	@$(MAKE) -C ./ft_printf fclean
	@$(MAKE) -C ./libft fclean
	@$(RM) server
	@$(RM) client
	@echo "[$(RED)deleted$(RESET)]: libft.a, libftprintf.a"

build:
	docker build -t arch .
	docker run -ti arch
prune:
	docker system prune -a --volumes

re: fclean all

.PHONY: all clean fclean re
