/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:47:52 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/19 17:30:54 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * It's going to the point and return the number of iteration.
 * Basically run the formula
 */
int	apply_formula(double c)
{
	int		i;
	double	z;

	z = 0;
	i = 0;
	while (i < 500 && fabs(z) <= 2)
	{
		z = pow(z, 2) + c;
		i++;
	}
	printf("%f:", z);
	return (i);
}

int	main(void)
{
	// printf("%d\n", apply_formula(1 + 0));
	// printf("%d\n", apply_formula(-1 + 1));
	// printf("%d\n", apply_formula(-0.5 + 0.1));
	// printf("%d\n", apply_formula(-0.8 + -0.5));
	// printf("%d\n", apply_formula(-1.4 + 0));
	// printf("%d\n", apply_formula(-0.2 + 0.2));
	// printf("%d\n", apply_formula(-1.135 + -0));
	// printf("%d\n", apply_formula(-0.2 + -0.1));
	// printf("%d\n", apply_formula(-1.0 + 0));
	// printf("%d\n", apply_formula(-1.2 + -1.2));
	// printf("%d\n", apply_formula(-1.8 + -0.775));
	return (0);
}
