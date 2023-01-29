NAME		=	fractol

CC			= gcc
CFLAGS 		= -Wall -Werror -Wextra

SRC			= main.c fractols.c render_utils.c handle_events.c
OBJ			= ${SRC:.o:.c}
RM 			= rm -rf
LIBFT		= libft/libft.a
INCLUDES	= minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -O3

all: $(NAME)

$(NAME):
		@make -C libft
		$(CC) ${SRC} ${INCLUDES} ${LIBFT} -o ${NAME}

clean:
		@make clean -C libft
		rm -rf ${NAME}

fclean:
		@make fclean -C libft
re:
		
val:
		$(CC) ${SRC} ${INCLUDES} ${LIBFT}
		valgrind -s --leak-check=full --show-leak-kinds=all ./a.out m