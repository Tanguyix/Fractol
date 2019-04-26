/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:23:13 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/10 10:48:32 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	ft_strlen_trim(char const *s)
{
	int		i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		if (!*s)
			return (-1);
	}
	while (*s)
	{
		i++;
		s++;
	}
	s--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s--;
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*s_trim;
	int		lenght;
	int		i;

	if (!s)
		return (0);
	i = 0;
	lenght = ft_strlen_trim(s);
	if (lenght == -1)
	{
		if (!(s_trim = malloc(sizeof(char) * 1)))
			return (NULL);
		*s_trim = '\0';
		return (s_trim);
	}
	if (!(s_trim = malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (lenght--)
		s_trim[i++] = *s++;
	s_trim[i] = '\0';
	return (s_trim);
}
