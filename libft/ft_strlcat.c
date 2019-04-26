/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:44:01 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/10 10:16:03 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_s;
	size_t		len_d;

	i = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (size < len_d)
		return (size + len_s);
	while (src[i] && (len_d + i + 1) < size)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
