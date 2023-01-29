/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:54 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/29 17:43:50 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ! We just need to free memory that was allocatted with malloc!!!
 * ! https://tronche.com/gui/x/xlib/events/ -> events doc
 * https://pt.wikipedia.org/wiki/Interpola%C3%A7%C3%A3o_linear or bitshifting
 * Optimazy the with no outter function!
 * https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set 
 * Need to create atof;
 * Need to take alnumstring;
 * copy the same files with bonus written onto makefile;
 * 
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

float	ft_atof(const char	*s)
{
	float	n;
	char	*decimal;
	int		signal;

	signal = 1;
	if (s[0] == '-')
		signal = -1;
	n = atoi(s);
	if (n < 0)
		n *= -1;
	decimal = strchr(s, '.');
	if (decimal && decimal == strrchr(s, '.'))
		n += (atoi(&decimal[1]) / pow(10, strlen(&decimal[1])));
	return (n * signal);
}

int	init_args(t_scr *scr, int argc, char *argv[])
{
	char	c;

	if (!((argc == 2 || argc == 4) && strchr("mjacb", argv[1][0])))
		return (write(1, MSG, M_SIZE));
	scr->point.real = 0;
	scr->point.imag = 0;
	c = argv[1][0];
	if (c == 'm')
		scr->f = &mandelbrot;
	if (c == 'b')
		scr->f = &burning_ship;
	if (c == 'a')
		scr->f = &alien;
	if (c == 'c')
		scr->f = &celtic;
	if (c == 'j')
	{
		if (argc != 4)
			return (write(1, MSG, M_SIZE));
		scr->f = &julia;
		scr->point.real = atof(argv[2]);
		scr->point.imag = atof(argv[3]);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_scr	scr;

	if (init_args(&scr, argc, argv) != 1)
		return (0);
	if (!init_screen(&scr))
		return (0);
	scr.stats.color = '1';
	scr.stats.zoom = 2;
	scr.stats.it = 0;
	event_handler(0, 0, 0, &scr);
	mlx_hook(scr.win, 17, 1L << 17, &destroy_window, &scr);
	mlx_hook(scr.win, KeyPress, KeyPressMask, &key_handler, &scr);
	mlx_mouse_hook(scr.win, &mouse_handler, &scr);
	mlx_loop(scr.mlx);
	return (0);
}
