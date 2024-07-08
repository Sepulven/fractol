/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:16:16 by asepulve          #+#    #+#             */
/*   Updated: 2024/07/08 23:53:46 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*
 * LERP stands for Linear Interpolation, which is a math operation that simply
 * blends 2 values given a percentage.

 * Only works with RGB colour, max a byte of length.
 * Alpha is a percentage.
*/
unsigned char	lerp(unsigned int start, unsigned int finish, double alpha)
{
	unsigned int result;

	if (alpha < 0.0) alpha = 0.0;
	if (alpha > 1.0) alpha = 1.0;

	result = (int)((1 - alpha) * (double)start + alpha * (double)finish);

	if (result > 255) result = 255;
	return (result);
}

unsigned int	get_color(unsigned int c1, unsigned int c2,
			int i, t_stats *stats)
{
	int				c;
	unsigned char	*p;

	p = (unsigned char *)&c;
	p[0] = lerp(c1, c2, (float)i / (stats->it + MAX_IT));
	p[1] = lerp(c1 >> 8, c2 >> 8, (float)i / (stats->it + MAX_IT));
	p[2] = lerp(c1 >> 16, c2 >> 16, (float)i / (stats->it + MAX_IT));
	return (c);
}

t_cx	converter(double x, double y, t_stats stats)
{
	return ((t_cx){
		(((x - W_WIDTH / 2) / stats.zoom) + stats.offset_x) / ZM,
		(((W_HEIGHT / 2 - y) / stats.zoom) + stats.offset_y) / ZM
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

int	render_img(t_scr *scr)
{
	int		x;
	int		y;
	int		i;
	int		color;
	t_cx	coordenates;
	t_stats *stats;

	if (!scr->img.fractol)
		return (1);

	y = 0;
	stats = &scr->stats;

	double width_unit = fabs(stats->max_x - stats->min_x) / W_WIDTH;
	double height_unit = fabs(stats->max_y - stats->min_y) / W_HEIGHT;

	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			coordenates = (t_cx) {
				(stats->min_x + width_unit * x),
				(stats->min_y + height_unit * y)
			};

			i = scr->f(coordenates, scr->point, stats->it);
			color = get_color(C1, C2, i, stats);

			// * Image canvas (what we see, not the complex plane);
			img_put_pix(&scr->img, x++, y, color);
		}
		y++;
	}
	return (0);
}
