/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:26:47 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/10 15:13:31 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strlowcase(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]))
		{
			s[i] = ft_tolower(s[i]);
		}
		i++;
	}
	return (s);
}
