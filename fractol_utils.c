/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/27 18:18:47 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_cx z, int it)
{
	int		i;
	t_cx	c;

	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	c = z;
	while ((i < MAX_ITERATIONS + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
 		z = (t_cx){(z.real*z.real) - (z.imag*z.imag) + c.real, 
			 	fabs(z.real * z.imag) * -2 + c.imag};
		i++;
	}
	return (i);
}

//Alien
int	alien(t_cx z, int it)
{
	int		i;
	t_cx	c;

	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	c = z;
	while ((i < MAX_ITERATIONS + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
 		z = (t_cx){(-1 * fabs(z.real) * z.real) - fabs(z.imag * z.imag) + c.real, 
			 	(z.real * z.imag * 2) + c.imag};
		i++;
	}
	return (i);
}

int	celtic(t_cx z, int it)
{
	int		i;
	t_cx	c;

	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	c = z;
	while ((i < MAX_ITERATIONS + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
		z = (t_cx){fabs((z.real * fabs(z.real)) + (z.imag * z.imag)) + c.real,
			 	(z.real * z.imag * 2) + c.imag};
		i++;
	}
	return (i);
}

int	mandelbrot(t_cx z, int it)
{
	int		i;
	t_cx	c;

	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	c = z;
	while ((i < MAX_ITERATIONS + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
			z = (t_cx){pow(z.real, 2) - pow(z.imag, 2) + c.real,
 			 	2 * z.real * z.imag + c.imag};
		i++;
	}
	return (i);
}
