/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:41 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/22 16:30:32 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(int keysym, t_scr *scr)
{
	if (keysym != XK_Escape)
		return (0);
	mlx_destroy_window(scr->mlx, scr->win);
	scr->win = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

int	destroy_window(t_scr *scr)
{
	mlx_destroy_window(scr->mlx, scr->win);
	exit(EXIT_SUCCESS);
	return (0);
}
