/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:12:37 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/06 16:00:35 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j] && n--)
	{
		dest[i] = src[j++];
		i++;
	}
	if (n)
		dest[i] = '\0';
	return (dest);
}
