/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:16:16 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/29 00:16:44 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	p[0] = lerp(c1 & ~0, c2 & ~0, (float)i / (float)max);
	/*Psicodelico rosa*/
	// p[1] = lerp(c1 >> 8 & ~0, c2 >> 8 & ~0, (float)i / (float)max);
	// p[2] = lerp(c1 >> 16 & ~0, c2 >> 16 & ~0, (float)i / (float)max);
	
	/* Verde gradient smooth*/
	//p[0] = lerp(c1 & ~0, c2 & ~0, (float)i / (float)max);
	// p[1] = lerp(c1 >> 16 & ~0, c2 >> 16 & ~0, (float)i / (float)max);
	// p[2] = lerp(c1 >> 24 & ~0, c2 >> 24 & ~0, (float)i / (float)max);
	
	/*Purple*/
	p[1] = lerp(c1 << 24 & ~0, c2 << 24 & ~0, (float)i / (float)max);
	p[2] = lerp(c1 << 16 & ~0, c2 << 16 & ~0, (float)i / (float)max);
	p[3] = lerp(c1 << 8& ~0, c2 << 8 & ~0, (float)i / (float)max);
	
	/* Double gradient */
	// p[0] = lerp(c1 & ~0, c2 & ~0, (float)i / (float)max);
	// p[1] = lerp(c1 >> 8 & ~0, c2 >> 8 & ~0, (float)i / (float)max) >> 8;
	// p[2] = lerp(c1 >> 16 & ~0, c2 >> 16 & ~0, (float)i / (float)max) >> 16;

	return (c);
}

t_cx	converter(double x, double y, t_stats stats)
{
	return ((t_cx){
		((x / stats.zoom) + stats.offset_x) / zm,
		((y / stats.zoom) + stats.offset_y) / zm
	});
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

int	render_img(t_scr *scr, t_stats stats)
{
	int		x;
	int		y;
	int		i;
	int		color;

	if (!scr->img.fractol)
		return (1);
	y = 0;
	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			i = scr->f(converter(x - W_WIDTH / 2, W_HEIGHT / 2 - y, stats), scr->point , stats.it);
			color =  get_color(0xFF0066, 0x002211, i, stats.it + MAX_ITERATIONS);
			img_put_pix(&scr->img, x++, y, color);
		}
		y++;
	}
	return (0);
}
