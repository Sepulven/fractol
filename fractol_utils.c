/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/27 16:53:42 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cx	converter(double x, double y, t_stats stats)
{
	return ((t_cx){
		((x / stats.zoom) + stats.offset_x) / zm,
		((y / stats.zoom) + stats.offset_y) / zm
	});
}

/*
 * It's going to the point and return the number of iteration.
 * Basically run the formula
 */
// int	mandelbrot(t_cx z, int it)
// {
// 	int		i;
// 	t_cx	c;

// 	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
// 		return (0);
// 	i = 0;
// 	c = z;
// 	while ((i < MAX_ITERATIONS + it) && (pow(z.imag, 2) + pow(z.real, 2) <= 4))
// 	{
// 		z = (t_cx){pow(z.real, 2) - pow(z.imag, 2) + c.real,
// 				 	2 * z.real * z.imag + c.imag};
// 		i++;
// 	}
// 	return (i);
// }

/*Burning ship upside down*/
// int	mandelbrot(t_cx z, int it)
// {
// 	int		i;
// 	t_cx	c;

// 	if ((pow(z.imag, 2) + pow(z.real, 2) >= 4))
// 		return (0);
// 	i = 0;
// 	c = z;
// 	while ((i < MAX_ITERATIONS + it) && (pow(z.imag, 2) + pow(z.real, 2) < 4))
// 	{
// 		z = (t_cx){(z.real*z.real) - (z.imag*z.imag) + c.real, 
// 				 	fabs(2 * z.real * z.imag) + c.imag};
// 		i++;
// 	}
// 	return (i);
// }

// Burning ship

// 		z = (t_cx){(z.real*z.real) - (z.imag*z.imag) + c.real, 
// 				 	fabs(z.real * z.imag) * -2 + c.imag};
// 		i++;

//Alien

// 		z = (t_cx){(-1 * fabs(z.real) * z.real) - fabs(z.imag * z.imag) + c.real, 
// 				 	(z.real * z.imag * 2) + c.imag};

//Washing machine
		// z = (t_cx){(-1 * fabs(z.real) * z.real) - (fabs(z.imag) * z.imag) + c.real, 
		// 		 	(fabs(z.real) * z.imag * -2) + c.imag};
//Celtic point
		// z = (t_cx){fabs((z.real * fabs(z.real)) + (z.imag * z.imag)) + c.real,
		// 		 	(z.real * z.imag * 2) + c.imag};

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
		z = (t_cx){(-1 * fabs(z.real) * z.real) - fabs(z.imag * z.imag) + c.real, 
			 	(z.real * z.imag * 2) + c.imag};
		i++;
	}
	return (i);
}


// int mandelbrot(t_cx z, int it)
// {
// 	int		i;
// 	double	x2;
// 	double	y2;
// 	t_cx	c;
	
// 	i = 0;
// 	c = z;
// 	x2 = 0;
// 	y2 = 0;
// 	while (x2 + y2 <= 4 && i < MAX_ITERATIONS + it)
// 	{
// 		z.real = 2 * z.real * z.imag + c.real;
// 		z.imag = x2 - y2 + c.imag;
// 		x2 = z.real * z.real;
//     	y2 = z.imag * z.imag;
// 		i++;
// 	}
// 	return (i);
// }
