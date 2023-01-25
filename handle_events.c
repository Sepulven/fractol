/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:41 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/25 13:31:02 by asepulve         ###   ########.fr       */
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
		event_handler(button, x - W_WIDTH / 2, W_HEIGHT / 2 - y, scr);
}

int	key_handler(int key, t_scr *scr)
{
	if (scr->win == NULL)
		return (0);
	if (key == XK_Escape)
		return (destroy_window(scr));
	if (key == XK_Up || key == XK_Down || key ==  XK_Right|| key == XK_Left)
		event_handler(key, 0, 0, scr);
	return (1);
}

int	event_handler(int key, int x, int y, t_scr *scr)
{
	static t_stats	stats;

	if (stats.zoom == 0)
		stats.zoom = 2;
	if (key == 4)
	{
		stats.zoom *= 2;
		stats.offset_x += x / stats.zoom;
		stats.offset_y += y / stats.zoom; 
	}
	if (key == 5)
		stats.zoom /= 2;
	if (key == XK_Up)
		stats.offset_y -= W_HEIGHT / (20 * stats.zoom);
	if (key == XK_Down)
		stats.offset_y += W_HEIGHT / (20 * stats.zoom);
	if (key == XK_Right)
		stats.offset_x -= W_WIDTH / (20 * stats.zoom);
	if (key == XK_Left)
		stats.offset_x += W_WIDTH / (20 * stats.zoom);
	render_img(&scr->img, mandelbrot, stats);
	mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);
	return (0);
}
