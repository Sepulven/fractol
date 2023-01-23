/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cx_operations_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:24:33 by asepulve          #+#    #+#             */
/*   Updated: 2023/01/23 13:10:29 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_cx	add_cx(t_cx comp1, t_cx comp2)
{
	return ((t_cx){comp1.real + comp2.real, comp1.imag + comp2.imag});
}

t_cx	multiply_cx(t_cx comp1, t_cx comp2)
{
	t_cx	result;

	result.real = (comp1.real * comp2.real) - (comp1.imag * comp2.imag);
	result.imag = (comp1.real * comp2.imag) + (comp1.imag * comp2.real);
	return (result);
}

t_cx	pow_cx(t_cx comp1)
{
	return (multiply_cx(comp1, comp1));
}

int	fabs_cx(t_cx comp)
{
	return (sqrt((comp.real * comp.real) + (comp.imag * comp.imag)));
}
