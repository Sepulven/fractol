/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:41 by asepulve          #+#    #+#             */
/*   Updated: 2024/07/28 23:40:50 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(t_scr *scr)
{
	mlx_destroy_image(scr->mlx, scr->img.fractol);
	mlx_clear_window(scr->mlx, scr->win);
	mlx_destroy_window(scr->mlx, scr->win);
	mlx_destroy_display(scr->mlx);
	free(scr->mlx);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_scr *scr)
{
	if (button == 5 || button == 4)
		event_handler(button, x - W_WIDTH / 2, W_HEIGHT / 2 - y, scr);
	return (1);
}

int	key_handler(int key, t_scr *scr)
{
	if (scr->win == NULL)
		return (0);
	if (key == XK_Escape)
		return (destroy_window(scr));
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left
		|| key == XK_KP_Subtract || key == XK_KP_Add
		|| key == '1' || key == '2' || key == '3')
	{
		if (strchr("123", key))
			scr->stats.color = key;
		if (key == XK_KP_Add)
			scr->stats.it += 10;
		if (key == XK_KP_Subtract)
			scr->stats.it -= 10;
		if (key == XK_Up)
			scr->stats.offset_y -= W_HEIGHT / (20 * scr->stats.zoom);
		if (key == XK_Down)
			scr->stats.offset_y += W_HEIGHT / (20 * scr->stats.zoom);
		if (key == XK_Right)
			scr->stats.offset_x -= W_WIDTH / (20 * scr->stats.zoom);
		if (key == XK_Left)
			scr->stats.offset_x += W_WIDTH / (20 * scr->stats.zoom);
		event_handler(0, 0, 0, scr);
	}
	return (1);
}

void	event_handler(int key, int x, int y, t_scr *scr)
{
	(void)x;(void) y;

	if (key == SCROLL_DOWN)
	{
		printf("x: %d -- y: %d\n", x, y);
		scr->stats.min_x /= 1.1;
		scr->stats.max_x /= 1.1;
		scr->stats.min_y /= 1.1;
		scr->stats.max_y /= 1.1;
	}
	if (key == SCROLL_UP)
	{
		printf("x: %d | y: %d\n", x, y);
		scr->stats.min_x *= 1.1;
		scr->stats.max_x *= 1.1;
		scr->stats.min_y *= 1.1;
		scr->stats.max_y *= 1.1;
	}
	render_img(scr);
	mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);
}
