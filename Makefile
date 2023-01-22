NAME	=	fractol

CC	= gcc
CFLAGS = -Wall -Werror -Wextra

SRC	= main.c fractol_utils.c complex_operations.c
OBJ	= ${SRC:.o:.c}

all: $(NAME)

$(NAME):
	$(CC) ${SRC} minilibx-linux/libmlx_Linux.a -lX11 -lXext  -lm
