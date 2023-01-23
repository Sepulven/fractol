/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 13:00:18 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * It's going to the point and return the number of iteration.
 * Basically run the formula
 */
int	mandelbrot_formula(double x, double y)
{
	int		i;
	t_cx	z;
	t_cx	c;

	c.real = (x  +  4000) / 10000;
	c.imag = (y  +  4000) / 10000;
	i = 0;
	z = c;
	while (i < MAX_ITERATIONS && fabs_cx(z) <= 2)
	{
		z = add_cx(pow_cx(z), c);
		i++;
	}
	return (i);
}
