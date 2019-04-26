/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:57:56 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/08 11:53:09 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static	int	ft_size_int(long n)
{
	int		len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		isneg;
	char	*ito;
	int		size;
	long	n_long;

	n_long = (long)n;
	isneg = 0;
	if (n_long < 0)
	{
		isneg = 1;
		n_long = -n_long;
	}
	size = ft_size_int(n_long) + isneg;
	if (!(ito = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ito[size] = '\0';
	while (size--)
	{
		ito[size] = (n_long % 10) + '0';
		n_long /= 10;
	}
	if (isneg)
		ito[0] = '-';
	return (ito);
}
