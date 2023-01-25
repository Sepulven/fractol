/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:54 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/25 13:33:24 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ! We just need to free memory that was allocatted with malloc!!!
 * ! https://tronche.com/gui/x/xlib/events/ -> events doc
 * https://pt.wikipedia.org/wiki/Interpola%C3%A7%C3%A3o_linear or bitshifting
 * Optimazy the with no outter function!
 * https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set 
 * TODO: Understand the algorithm behind the colors
 * TODO: Make image be already zoomed whenever it starts;
 * TODO: Create julia;
 */
#include "fractol.h"

int	render(t_scr *scr, t_stats stats)
{
	if (!scr->mlx)
		return (MLX_ERROR);
	render_img(&scr->img, &mandelbrot, stats);
	return (0);
}

int	init_screen(t_scr *scr)
{
	scr->mlx = mlx_init();
	if (!scr->mlx)
		return (0);
	scr->win = mlx_new_window(scr->mlx, W_WIDTH, W_HEIGHT, "Fractol-asepulve");
	if (!scr->win)
	{
		free(scr->win);
		return (0);
	}
	scr->img.fractol = mlx_new_image(scr->mlx, W_WIDTH, W_WIDTH);
	scr->img.addr = mlx_get_data_addr(scr->img.fractol,
			&scr->img.bpp, &scr->img.line_len, &scr->img.endian);
	return (1);
}

int	main(void)
{
	t_scr	scr;

	if (!init_screen(&scr))
		return (0);
	event_handler(0, 0, 0, &scr);
	mlx_hook(scr.win, 17, 1L << 17, &destroy_window, &scr);
	mlx_hook(scr.win, KeyPress, KeyPressMask, &key_handler, &scr);
	mlx_mouse_hook(scr.win, &mouse_handler, &scr);
	mlx_loop(scr.mlx);
	return (0);
}
