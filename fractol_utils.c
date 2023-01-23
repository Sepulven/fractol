/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 20:39:26 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cx	converter(double x, double y, t_stats stats)
{
	return ((t_cx){
		(x + stats.offset_x / stats.zoom),
		(y + stats.offset_y/ stats.zoom)
	});
}

/*
 * It's going to the point and return the number of iteration.
 * Basically run the formula
 */

int	mandelbrot(t_cx z)
{
	int		i;
	t_cx	c;
	double	real;

	c = z;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (sqrt(pow(z.imag, 2) + pow(z.real, 2)) >= 2)
			break ;
		real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = real;
		i++;
	}
	return (i);
}

		//z = add_cx(pow_cx(z), c);
	// while (i < MAX_ITERATIONS && fabs_cx(z) <= 2)
	// {
	// 	//z = add_cx(pow_cx(z), c);
	// 	real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
	// 	z.imag = 2 * z.real * z.imag;
	// 	z.real = real;
	// 	i++;
	// }
