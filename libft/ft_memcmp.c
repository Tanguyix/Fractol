/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:43:02 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/08 11:53:40 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	s1_cast = (unsigned char*)s1;
	s2_cast = (unsigned char*)s2;
	while (n--)
	{
		if (*s1_cast - *s2_cast)
			return (*s1_cast - *s2_cast);
		s1_cast++;
		s2_cast++;
	}
	return (0);
}
