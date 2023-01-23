/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:54 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 12:50:25 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ! We just need to free memory that was allocatted with malloc!!!
 * https://tronche.com/gui/x/xlib/events/ -> events doc
 */
#include "fractol.h"

int	render(t_scr *scr)
{
	if (!scr->mlx)
		return (MLX_ERROR);
	render_img(&scr->img);
	mlx_put_image_to_window(scr->mlx, scr->win, scr->img.fractol, 0, 0);
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
	render(&scr);
	if (!scr.mlx)
		write(1, "ok\n", 3);
	mlx_hook(scr.win, 17, 1L << 17, &destroy_window, &scr);
	mlx_hook(scr.win, KeyPress, KeyPressMask, &key_handling, &scr);
	mlx_loop(scr.mlx);
	return (0);
}
