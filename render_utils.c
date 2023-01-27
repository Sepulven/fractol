/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:16:16 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/27 17:02:01 by asepulve         ###   ########.fr       */
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

unsigned char	lerp(unsigned int a, unsigned int b, double t)
{
	return ((int)((1 - t) * (double)a + t * (double)b));
}

unsigned int	get_color(unsigned int c1, unsigned int c2, int i, int max)
{
	int	c;
	unsigned char *p;
	
	if (i == max)
		return (0x000000);
	p = (unsigned char *)&c;

	/*Psicodelico rosa*/
	// p[0] = lerp(c1 & ~0, c2 & ~0, (float)i / (float)max);
	// p[1] = lerp(c1 >> 8 & ~0, c2 >> 8 & ~0, (float)i / (float)max);
	// p[2] = lerp(c1 >> 16 & ~0, c2 >> 16 & ~0, (float)i / (float)max);
	
	/* Verde gradient smooth*/
	p[0] = lerp(c1 & ~0, c2 & ~0, (float)i / (float)max);
	p[1] = lerp(c1 >> 16 & ~0, c2 >> 16 & ~0, (float)i / (float)max);
	p[2] = lerp(c1 >> 24 & ~0, c2 >> 24 & ~0, (float)i / (float)max);
	
	/*Purple*/
	// p[1] = lerp(c1 << 24 & ~0, c2 << 24 & ~0, (float)i / (float)max);
	// p[2] = lerp(c1 << 16 & ~0, c2 << 16 & ~0, (float)i / (float)max);
	// p[3] = lerp(c1 << 8& ~0, c2 << 8 & ~0, (float)i / (float)max);
	
	/* Double gradient */
	// p[0] = lerp(c1 & ~0, c2 & ~0, (float)i / (float)max);
	// p[1] = lerp(c1 >> 8 & ~0, c2 >> 8 & ~0, (float)i / (float)max) >> 8;
	// p[2] = lerp(c1 >> 16 & ~0, c2 >> 16 & ~0, (float)i / (float)max) >> 16;

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

int	render_img(t_img *img, int (*f)(t_cx z, int i), t_stats stats)
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
			i = f(converter(x - W_WIDTH / 2, W_HEIGHT / 2 - y, stats), stats.it);
			color =  get_color(0xFF0066, 0x002211, i, stats.it + MAX_ITERATIONS);
			img_put_pix(img, x++, y, color);
		}
		y++;
	}
	return (0);
}
