/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:41 by asepulve          #+#    #+#             */
/*   Updated: 2024/08/13 00:25:31 by asepulve         ###   ########.fr       */
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


/*
 * Converts the coordenates to a vector.
*/
int	mouse_handler(int button, int x, int y, t_scr *scr)
{
	if (button == SCROLL_DOWN || button == SCROLL_UP)
		event_handler(button, x - W_WIDTH / 2, W_HEIGHT / 2 - y, scr);
	return (1);
}

int	key_handler(int key, t_scr *scr)
{
	float x_span = fabs(scr->stats.max_x - scr->stats.min_x);
	float y_span = fabs(scr->stats.max_y - scr->stats.min_y);

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
		{
			scr->stats.min_y += y_span / 10;
			scr->stats.max_y = scr->stats.min_y + y_span;
		}
		if (key == XK_Down)
		{
			scr->stats.min_y -= y_span / 10;
			scr->stats.max_y = scr->stats.min_y + y_span;
		}
		if (key == XK_Right)
		{
			scr->stats.min_x -= x_span / 10;
			scr->stats.max_x = scr->stats.min_x + x_span;
		}
		if (key == XK_Left)
		{
			scr->stats.min_x += x_span / 10;
			scr->stats.max_x = scr->stats.min_x + x_span;
		}
		render_img(scr);
		mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);

	}
	return (1);
}

/*
 * (x, y) is a vector, we are going change its proportions;
*/
void	event_handler(int key, int x, int y, t_scr *scr)
{
	if (x == 0 && y == 0)
	{
		render_img(scr);
		mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);
		return ;
	}

	printf("x: %d y: %d\n", x, y); // * I need to scale this x and y

	float width = fabs(scr->stats.max_x - scr->stats.min_x);
	float heigth = fabs(scr->stats.max_y - scr->stats.min_y);

	if (key == SCROLL_DOWN)
	{
		scr->stats.min_x /= 1.1;
		scr->stats.max_x /= 1.1;
		scr->stats.min_y /= 1.1;
		scr->stats.max_y /= 1.1;
	}
	if (key == SCROLL_UP)
	{
		scr->stats.min_x *= 1.1;
		scr->stats.max_x *= 1.1;
		scr->stats.min_y *= 1.1;
		scr->stats.max_y *= 1.1;
	}


	float zoom_width = fabs(scr->stats.max_x - scr->stats.min_x);
	float zoom_heigth = fabs(scr->stats.max_y - scr->stats.min_y);

	float x_0 = x, y_0 = y;
	// * x_0 and y_0 are the coordenates of the new point;
	float rel_x = x_0 / width; // * calc the relative position of x
	// * proportion rule applies in this scenario
	float rel_y = y_0 / heigth; // * calc the relative position of y
	
	// * Calc the coordenates of the visible area
	scr->stats.min_x = x_0 - rel_x * zoom_width;
	scr->stats.min_y = y_0 - rel_y * zoom_heigth;

	scr->stats.max_x = scr->stats.min_x - width;
	scr->stats.max_y = scr->stats.max_y - heigth;

	render_img(scr);
	mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);
}
