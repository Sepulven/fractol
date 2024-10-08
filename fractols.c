/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2024/07/07 00:07:43 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	* The only reason all of these function has the t_cx j param is the julia set.
*/

int	burning_ship(t_cx z, t_cx j, int it)
{
	int		i;
	t_cx	c;

	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	(void)j;
	c = z;
	while ((i < MAX_IT + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
		z = (t_cx){(z.real * z.real) - (z.imag *z.imag) + c.real,
			fabs(z.real * z.imag) * -2 + c.imag};
		i++;
	}
	return (i);
}

int	alien(t_cx z, t_cx j, int it)
{
	int		i;
	t_cx	c;

	(void)j;
	c = z;
	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	while ((i < MAX_IT + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
		z = (t_cx){(-1 * fabs(z.real) * z.real)
			- fabs(z.imag * z.imag) + c.real, (z.real * z.imag * 2) + c.imag};
		i++;
	}
	return (i);
}

int	celtic(t_cx z, t_cx j, int it)
{
	int		i;
	t_cx	c;

	(void)j;
	c = z;
	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	while ((i < MAX_IT + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
		z = (t_cx){fabs((z.real * fabs(z.real)) + (z.imag * z.imag)) + c.real,
			(z.real * z.imag * 2) + c.imag};
		i++;
	}
	return (i);
}


/*
	* Julia needs the other imaginary point for it to render;
*/
int	julia(t_cx z, t_cx j, int it)
{
	int		i;

	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
		return (0);
	i = 0;
	while ((i < MAX_IT + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
			z = (t_cx){pow(z.real, 2) - pow(z.imag, 2) + j.real,
			2 * z.real * z.imag + j.imag};
		i++;
	}
	return (i);
}

/*
 * If the coordenate converge we return the iterarion iterator value;
*/
int	mandelbrot(t_cx z, t_cx j, int it)
{
	int		i;
	t_cx	c;

	(void)j;
	i = 0;
	c = z;
	while ((i < MAX_IT + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
	{
		z = (t_cx){
				pow(z.real, 2) - pow(z.imag, 2) + c.real,
				2 * z.real * z.imag + c.imag
			};
		i++;
	}
	return (i);
}
