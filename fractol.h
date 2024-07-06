/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:52:02 by asepulve          #+#    #+#             */
/*   Updated: 2024/07/06 02:00:52 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H 1

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <string.h>

# define MLX_ERROR 1
# define MAX_IT 30
# define ZM 200
# define C1 0xFFFFFF
# define C2 0x000000
# define W_HEIGHT 800
# define W_WIDTH 1280
# define MSG "Invalid options!\n LIST OF OPTIONS:\n m-> Mandelbrot\n c-> Celtic\n a-> Alien \n \
j-> Julia \n\t(needs to specify two float parameters)\n b-> Burning ship \n"
# define M_SIZE 148

typedef struct s_cx
{	
	double	real;
	double	imag;
}	t_cx;

typedef struct s_stats
{
	double	offset_x;
	double	offset_y;
	double	zoom;
	float	it;
	char	color;
}	t_stats;

typedef struct s_img
{
	void	*fractol;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_scr
{
	void	*mlx;
	void	*win;
	int		(*f)(t_cx, t_cx, int);
	t_cx	point;
	t_stats	stats;
	t_img	img;
}	t_scr;

/*handle_events.c*/
int		destroy_window(t_scr *scr);
int		key_handler(int key, t_scr *scr);
int		mouse_handler(int button, int x, int y, t_scr *scr);
void	event_handler(int key, int x, int y, t_scr *scr);

/*render_utils.c*/
void	img_put_pix(t_img *img, int x, int y, int color);
int		render_img(t_scr *scr);
t_cx	converter(double x, double y, t_stats stats);

/*fractol_utils.c*/
int		mandelbrot(t_cx z, t_cx c, int iterations);
int		burning_ship(t_cx z, t_cx c, int it);
int		alien(t_cx z, t_cx c, int it);
int		celtic(t_cx z, t_cx c, int it);
int		julia(t_cx z, t_cx c, int it);
#endif
