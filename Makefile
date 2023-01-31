NAME		=	fractol

CC			= gcc
CFLAGS 		= -Wall -Werror -Wextra

SRC			= fractols.c render_utils.c handle_events.c main.c
OBJ			= $(SRC:.c=.o)
RM 			= rm -rf
INCLUDES	= minilibx-linux/libmlx_Linux.a -lm -lX11 -lXext

.c:.o

all: $(NAME)

$(NAME): ${OBJ}
		gcc ${SRC} ${INCLUDES} -O3 -c
		gcc fractols.o render_utils.o handle_events.o main.o ${INCLUDES} -o ${NAME}

clean:
		@make clean -C libft
		rm -rf ${OBJ}

fclean: clean
		@make fclean -C libft
		rm -rf ${NAME}
re: fclean ${NAME}

val:
		$(CC) ${SRC} ${INCLUDES} ${LIBFT}
		valgrind -s --leak-check=full --show-leak-kinds=all ./a.out m