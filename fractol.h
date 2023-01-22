/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:52:02 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/21 00:27:41 by asepulve         ###   ########.fr       */
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

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 2000
# define MLX_ERROR 1
# define MAX_ITERATIONS 100

typedef struct s_comp
{
	double	real;
	double	imag;
}	t_comp;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_screen;


void	img_put_pix(t_img *img, int x, int y, int color);
int		render_img(t_img *img);
int		apply_mandelbrot_formula(double x, double y);

t_comp	add_comp(t_comp comp1, t_comp comp2);
t_comp	multiply_comp(t_comp comp1, t_comp comp2);
t_comp	pow_comp(t_comp comp1);
int		fabs_comp(t_comp comp);
#endif
