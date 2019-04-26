/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:56:53 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/08 11:57:44 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ans;
	char	*start;

	start = (char *)s;
	ans = (NULL);
	while (*s)
		s++;
	while (*s != c && s != start)
		s--;
	if (*s == c)
		ans = (char *)s;
	return (ans);
}
