/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:09:29 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/06 16:21:57 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		length;
	int		i;
	int		j_need;

	if (!(length = ft_strlen(needle)))
		return ((char *)haystack);
	i = 0;
	j_need = 0;
	while (haystack[i])
	{
		while (haystack[i + j_need] == needle[j_need])
		{
			if (j_need == length - 1)
				return ((char *)haystack + i);
			j_need++;
		}
		j_need = 0;
		i++;
	}
	return (0);
}
