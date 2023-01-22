/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:52:02 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/22 16:30:45 by asepulve         ###   ########.fr       */
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

// # define WINDOW_WIDTH 1366
// # define WINDOW_HEIGHT 768

# define W_WIDTH 1280
# define W_HEIGHT 800
# define MLX_ERROR 1
# define MAX_ITERATIONS 500

typedef struct s_cx
{
	double	real;
	double	imag;
}	t_cx;

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
	t_img	img;
}	t_scr;

/*handle_events.c*/
int		destroy_window(t_scr *scr);
int		close_window(int keysym, t_scr *scr);

/*render_utils.c*/
void	img_put_pix(t_img *img, int x, int y, int color);
int		render_img(t_img *img);

/*fractol_utils.c*/
int		mandelbrot_formula(double x, double y);

/*cx_operations_utils.c*/
t_cx	add_cx(t_cx comp1, t_cx comp2);
t_cx	multiply_cx(t_cx comp1, t_cx comp2);
t_cx	pow_cx(t_cx comp1);
int		fabs_cx(t_cx comp);
#endif
