NAME	=	fractol

CC	= gcc
CFLAGS = -Wall -Werror -Wextra -O3

SRC	= main.c fractol_utils.c render_utils.c handle_events.c
OBJ	= ${SRC:.o:.c}

all: $(NAME)

$(NAME):
	$(CC) ${SRC} minilibx-linux/libmlx_Linux.a -lX11 -lXext  -lm -O3
	./a.out

val:
		$(CC) ${SRC} -g minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -O3
		valgrind --leak-check=full --show-leak-kinds=all ./a.out