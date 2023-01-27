/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:54 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/27 17:32:50 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ! We just need to free memory that was allocatted with malloc!!!
 * ! https://tronche.com/gui/x/xlib/events/ -> events doc
 * https://pt.wikipedia.org/wiki/Interpola%C3%A7%C3%A3o_linear or bitshifting
 * Optimazy the with no outter function!
 * https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set 
 * TODO: Create julia;
 * z = (abs(x) + abs(y)i)^2 + c ou z = (x + yi)^2 + c
 */
#include "fractol.h"

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

#include <string.h>

int	init_args(t_scr *scr, int argc, char *argv[])
{
	if (argc == 2 || argc == 3)
	{
		if (strchr("mjacb", argv[1][0]))
			scr->f_type = argv[1][0];
		else 
			return (write(1, MSG, 133));
		if (argc == 3)
		{
			if (strchr("pdgv", argv[1][1]))
				scr->f_type = argv[2][1];
		}
		return (1);
	}
	return (write(1, MSG, 133));
}

int	main(int argc, char *argv[])
{
	t_scr	scr;
	if (!init_screen(&scr))
		return (0);
	if (init_args(&scr, argc, argv) != 1)
		return (0);
	event_handler(0, 0, 0, &scr);
	mlx_hook(scr.win, 17, 1L << 17, &destroy_window, &scr);
	mlx_hook(scr.win, KeyPress, KeyPressMask, &key_handler, &scr);
	mlx_mouse_hook(scr.win, &mouse_handler, &scr);
	mlx_loop(scr.mlx);
	return (0);
}
