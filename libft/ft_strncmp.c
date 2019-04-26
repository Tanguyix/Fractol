/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:59:41 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/08 11:57:23 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	s1_cast = (unsigned char*)s1;
	s2_cast = (unsigned char*)s2;
	while ((*s1_cast || *s2_cast) && n--)
	{
		if (*s1_cast - *s2_cast)
			return ((int)*s1_cast - *s2_cast);
		s1_cast++;
		s2_cast++;
	}
	return (0);
}
