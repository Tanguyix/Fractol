/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:42:50 by tboissel          #+#    #+#             */
/*   Updated: 2018/04/08 13:45:24 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstmapped;

	if (lst)
	{
		lstmapped = f(lst);
		lstmapped->next = ft_lstmap(lst->next, f);
		return (lstmapped);
	}
	return (0);
}
