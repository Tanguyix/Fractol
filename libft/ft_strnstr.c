/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:23:42 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 14:57:15 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	length;
	size_t	i;
	size_t	j_need;

	if (!(length = ft_strlen(needle)))
		return ((char*)haystack);
	if (n < length && needle && haystack)
		return (NULL);
	i = 0;
	j_need = 0;
	n = n - length + 1;
	while (haystack[i] && n--)
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
	return (NULL);
}
