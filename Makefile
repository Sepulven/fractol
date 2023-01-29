NAME	=	fractol

CC	= gcc
CFLAGS = -Wall -Werror -Wextra -O3

SRC	= main.c fractols.c render_utils.c handle_events.c
OBJ	= ${SRC:.o:.c}

all: $(NAME)

$(NAME):
	$(CC) ${SRC} minilibx-linux/libmlx_Linux.a -lX11 -lXext  -lm -O3

val:
		$(CC) ${SRC} -g minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -O3
		valgrind -s --leak-check=full --show-leak-kinds=all ./a.out m