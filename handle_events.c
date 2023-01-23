/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:41 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 12:55:57 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	destroy_window(t_scr *scr)
{
	mlx_destroy_window(scr->mlx, scr->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handling(int key, t_scr *scr)
{
	if (key == XK_Escape)
		destroy_window(scr);
	if (key == 'w')
		write(1, "w", 1);
	if (key == 's')
		write(1, "s", 1);
	if (key == 'd')
		write(1, "d", 1);
	if (key == 'a')
		write(1, "a", 1);
	
}

