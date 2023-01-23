/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:16:16 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 20:40:00 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	filter_color(int value)
{
	if (value == MAX_ITERATIONS)
		return (0x000000);
	if (value <= 10)
		return (0xFF0011);
	if (value <= 20)
		return (0x00FFFF);
	if (value <= 100)
		return (0x1000FF);
	if (value <= 200)
		return (0x0000FF);
	if (value <= 350)
		return (0x0CB1F1);
	if (value <= 450)
		return (0xABA0F1);
	if (value <= 700)
		return (0xABACF1);
	return (0xFF15f3);
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

int	render_img(t_img *img, int (*f)(t_cx z), t_stats stats)
{
	int		x;
	int		y;
	int		i;

	if (!img->fractol)
		return (1);
	y = 0;
	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			i = f(converter(x - W_WIDTH / 2, W_HEIGHT / 2 - y, stats));
			img_put_pix(img, x++, y, filter_color(i));
		}
		y++;
	}
	return (0);
}
