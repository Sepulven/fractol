/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:18:47 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/01 19:27:42 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while ((big[i]) && (i < len))
	{
		j = 0;
		while ((big[i] != little[j]))
			i++;
		temp = i;
		while ((little[j] == big[temp]) && (temp < len))
		{
			j++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
			temp++;
		}
		i++;
	}
	return (NULL);
}
