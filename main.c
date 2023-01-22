/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:54 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/20 21:00:41 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * ! We just need to free memory that was allocatted with malloc!!!
 */
#include "fractol.h"

int	render(t_screen *screen)
{
	if (!screen->mlx)
		return (MLX_ERROR);
	render_img(&screen->img);
	mlx_put_image_to_window(screen->mlx,
		screen->win, screen->img.mlx_img, 0, 0);
	return (0);
}

int	close_window(int keysym, t_screen *screen)
{
	if (keysym != XK_Escape)
		return (0);
	mlx_destroy_window(screen->mlx, screen->win);
	screen->win = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

/*
 * Handle the outcomes for a clean exit.
 * Needs to free properly the memory.
 */
int	main(void)
{
	t_screen	screen;

	screen.mlx = mlx_init();
	if (!screen.mlx)
		return (0);
	screen.win = mlx_new_window(screen.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol-asepulve");
	if (!screen.win)
	{
		free(screen.win);
		return (0);
	}
	screen.img.mlx_img = mlx_new_image(screen.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	screen.img.addr = mlx_get_data_addr(screen.img.mlx_img,
			&screen.img.bpp, &screen.img.line_len, &screen.img.endian);
	render(&screen);
	//mlx_loop_hook(screen.mlx, &render, &screen);
	mlx_hook(screen.win, KeyPress, KeyPressMask, &close_window, &screen);
	mlx_loop(screen.mlx);

	mlx_destroy_image(screen.mlx, screen.img.mlx_img);
	mlx_destroy_display(screen.mlx);
	free(screen.mlx);
	return (0);
}
