NAME	=	fractol

CC	= gcc
CFLAGS = -Wall -Werror -Wextra

SRC	= main.c 
OBJ	= ${SRC:.o:.c}

all: $(NAME)

$(NAME):
	$(CC) main.c minilibx-linux/libmlx_Linux.a -lX11 -lXext 

main2:
	$(CC) main2.c minilibx-linux/libmlx_Linux.a -lX11 -lXext

test:
	$(CC) fractol_utils.c minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
