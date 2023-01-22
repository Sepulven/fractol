/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/22 14:07:03 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
/*
 * It's going to the point and return the number of iteration.
 * Basically run the formula
 */
int	apply_mandelbrot_formula(double x, double y)
{
	int		i;
	t_comp	z;
	t_comp	c;

	c.real = x / 250;
	c.imag = y / 250;
	i = 0;
	z.real = 0;
	z.imag = 0;
	while (i < MAX_ITERATIONS && fabs_comp(z) <= 2)
	{
		z = add_comp(pow_comp(z), c);
		i++;
	}
	return (i);
}

/* 		index = line_len * y + x * (bpp / 8)
*	This is the formula that gives the 
*/
void	img_put_pix(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

static int	filter_color(int value)
{
	if (value == MAX_ITERATIONS)
		return (0x000000);
	if (value < 100)
		return (0xFF0011);
	return (0xFF15f3);
}

int	render_img(t_img *img)
{
	double	x;
	double	y;
	int		color;
	int		iterations;

	if (!img->mlx_img)
		return (1);
	y = 0;
	while (y <= WINDOW_HEIGHT)
	{
		x = 0;
		while (x <= WINDOW_WIDTH)
		{
			iterations = apply_mandelbrot_formula(x - WINDOW_WIDTH / 2,
					WINDOW_HEIGHT / 2 - y);
			//printf("%d ", iterations);
			img_put_pix(img, x++, y, filter_color(iterations));
		}
		y++;
	}
	return (0);
}
