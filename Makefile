NAME		=	fractol

CC			= gcc
CFLAGS 		= -Wall -Werror -Wextra

SRC			= main.c fractols.c render_utils.c handle_events.c
OBJ			= $(SRC:.c=.o)
RM 			= rm -rf
INCLUDES	= libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -O3

all: $(NAME)
.c:.o
	$(CC) $< ${INCLUDES} ${LIBFT}  -c
$(NAME): ${OBJ}
		@make -C libft
		$(CC) ${OBJ} ${INCLUDES} -o ${NAME}

clean:
		@make clean -C libft
		rm -rf ${OBJ}
fclean:
		@make fclean -C libft
		rm -rf ${NAME}
re: fclean ${NAME}

val:
		$(CC) ${SRC} ${INCLUDES} ${LIBFT}
		valgrind -s --leak-check=full --show-leak-kinds=all ./a.out m