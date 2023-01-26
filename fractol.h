/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:52:02 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/26 17:20:01 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H 1

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define MLX_ERROR 1
# define MAX_ITERATIONS 30
# define zm 200
# define W_HEIGHT 800
# define W_WIDTH 1280
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
	int		it;
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
	int		color;
	char	f_type;
	t_img	img;
}	t_scr;

/*handle_events.c*/
int	destroy_window(t_scr *scr);
int	key_handler(int key, t_scr *scr);
int	mouse_handler(int button, int x, int y, t_scr *scr);
void	event_handler(int key, int x, int y, t_scr *scr);

/*render_utils.c*/
void	img_put_pix(t_img *img, int x, int y, int color);
int		render_img(t_img *img, int (*f)(t_cx, int), t_stats stats);

/*fractol_utils.c*/
t_cx	converter(double x, double y, t_stats stats);
int		mandelbrot(t_cx z, int iterations);

/*cx_operations_utils.c*/
t_cx	add_cx(t_cx comp1, t_cx comp2);
t_cx	multiply_cx(t_cx comp1, t_cx comp2);
t_cx	pow_cx(t_cx comp1);
int		fabs_cx(t_cx comp);
#endif
