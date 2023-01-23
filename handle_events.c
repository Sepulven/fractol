/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:41 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 20:33:57 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(t_scr *scr)
{
	mlx_destroy_window(scr->mlx, scr->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_scr *scr)
{
	if (button == 5 || button == 4)
		event_handler(button, 0, 0, scr);
}

int	key_handler(int key, t_scr *scr)
{
	event_handler(key, 0, 0, scr);
	if (key == 'w' || key == 's' || key == 'd' || key == 'a')
		return (1);
}

int	event_handler(int key, int x, int y, t_scr *scr)
{
	static t_stats	stats;

	if (scr->win == NULL)
		return (0);
	if (key == XK_Escape)
		destroy_window(scr);
	if (stats.zoom == 0)
		stats.zoom = 2;
	if (key == 4)
		stats.zoom *= 2;
	if (key == 5)
		stats.zoom /= 2;
	if (key == 65362)
		stats.offset_y += 1;
	if (key == 65364)
		stats.offset_y -= 1;
	if (key == 65363)
		stats.offset_x += 1;
	if (key == 65361)
		stats.offset_x -= 1;
	render_img(&scr->img, mandelbrot, stats);
	mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);
	return (0);
}
