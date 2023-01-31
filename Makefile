NAME		=	fractol

CC			= gcc
CFLAGS 		= -Wall -Werror -Wextra

SRC			= fractols.c render_utils.c handle_events.c main.c
OBJ			= fractols.o render_utils.o handle_events.o main.o
RM 			= rm -rf
INCLUDES	= libft/libft.a minilibx-linux/libmlx_Linux.a -lm -lX11 -lXext

all: $(NAME)

$(NAME):
		@gcc ${SRC} -O3 -c
		@make -C libft
		@gcc ${OBJ} ${INCLUDES} -o ${NAME}

clean:
		@make clean -C libft
		@rm -rf ${OBJ}

fclean: clean
		@make fclean -C libft
		@rm -rf ${NAME}
re: fclean ${NAME}

val:
	valgrind -s --leak-check=full --show-leak-kinds=all ./a.out m
