/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 13:01:35 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * It's going to the point and return the number of iteration.
 * Basically run the formula
 */
int	mandelbrot_formula(t_cx z)
{
	int		i;
	t_cx	c;

	c = z;
	i = 0;
	while (i < MAX_ITERATIONS && fabs_cx(z) <= 2)
	{
		z = add_cx(pow_cx(z), c);
		i++;
	}
	return (i);
}
