/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 09:25:22 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/12 12:21:11 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = -1;
	str = ft_strlowcase(str);
	str[0] = ft_toupper(str[0]);
	while (str[++i])
		if (!(ft_isalnum(str[i])))
			str[i + 1] = ft_toupper(str[i + 1]);
	return (str);
}
