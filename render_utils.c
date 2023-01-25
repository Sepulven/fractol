/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:16:16 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/25 01:31:25 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// int get_color(int r, int g, int b)
// {
// 	int color;

// 	color = (color >> 24) | r;
// 	color = (color >> 16) | g;
// 	color = (color >> 8) | b;
// }

// static int	lerp(int c1, int c2, float t)
// {
// 	if (t == 1.00)
// 		return (0x000000);
	
// 	return (get_color(
// 			(0xFF0000 + (0xFF0000 + 0x00FF00) * t),
// 			(0xDDDD00 + (0xDDDD00 + 0x0F1100) * t),
// 			(0x335500 + (0x335500 + 0x005500) * t)
// 	));

// };


// int	get_color_from_index(unsigned int color_i)
// {
// 	const int	color_arr[] = {0x00000000, 0x0099d98c,
// 		0x0003071e, 0x006b9080,
// 		0x00ffffff, 0x001a759f,
// 		0x00ffba08, 0x00f6fff8};

// 	return (color_arr[color_i]);
// }

int	lerp(unsigned int a, unsigned int b, double t)
{
	return ((int)((1 - t) * (double)a + t * (double)b));
}

unsigned int	get_color(unsigned int c1, unsigned int c2, int i)
{
	unsigned int	c;

	if (i == MAX_ITERATIONS)
		return (0x000000);

	c = ((lerp(c1 >> 16 & 0xff, c2 >> 16 & 0xff, (float)i / (float)MAX_ITERATIONS)) << 16)
		| ((lerp(c1 >> 8 & 0xff, c2 >> 8 & 0xff, (float)i / (float)MAX_ITERATIONS)) << 8)
		| (lerp(c1 & 0xff, c2 & 0xff, (float)i / (float)MAX_ITERATIONS));
	return (c);
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
	int		color;

	if (!img->fractol)
		return (1);
	y = 0;
	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			i = f(converter(x - W_WIDTH / 2, W_HEIGHT / 2 - y, stats));
			color =  get_color(0xF01AA590, 0x0000ff8, i);
			img_put_pix(img, x++, y, color);
		}
		y++;
	}
	return (0);
}
