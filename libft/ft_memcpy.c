/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:07:57 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/06 15:02:52 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s_cast;
	char	*d_cast;

	s_cast = (char *)src;
	d_cast = (char *)dest;
	i = 0;
	while (i < n)
	{
		d_cast[i] = s_cast[i];
		i++;
	}
	return (d_cast);
}
