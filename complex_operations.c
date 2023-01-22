/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:24:33 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/20 21:26:34 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	add_comp(t_comp comp1, t_comp comp2)
{
	return ((t_comp){comp1.real + comp2.real, comp1.imag + comp2.imag});
}


t_comp	multiply_comp(t_comp comp1, t_comp comp2)
{
	t_comp	result;

	result.real = (comp1.real * comp2.real) - (comp1.imag * comp2.imag);
	result.imag = (comp1.real * comp2.imag) + (comp1.imag * comp2.real);
	return (result);
}

t_comp	pow_comp(t_comp comp1)
{
	return (multiply_comp(comp1, comp1));
}

int	fabs_comp(t_comp comp)
{
	return (sqrt((comp.real * comp.real) + (comp.imag * comp.imag)));
}
