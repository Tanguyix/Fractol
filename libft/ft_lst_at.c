/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:17:01 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/10 13:59:40 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *lst, unsigned int n)
{
	while (lst->next && n--)
		lst = lst->next;
	if (n == 0)
		return (lst);
	else
		return (NULL);
}
