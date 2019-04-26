/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:28:52 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 15:06:26 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_number_words(const char *s, char c)
{
	int		compteur;
	int		i;
	int		word;

	word = 0;
	i = 0;
	compteur = 0;
	while (s[i])
	{
		if (!(s[i] == c))
		{
			if (!word)
				compteur++;
			word = 1;
		}
		else
			word = 0;
		i++;
	}
	return (compteur);
}

static int	ft_len_split(char const *s, char c)
{
	int		compt;

	compt = 0;
	while (s[compt] && s[compt] != c)
		compt++;
	return (compt);
}

static char	**ft_actual_split(char const *s, char c, char **tab)
{
	int		i;
	int		word;
	int		k;

	k = 0;
	word = 0;
	i = 0;
	while (s[i])
	{
		if (!word && s[i] != c)
		{
			tab[k] = (char*)malloc((ft_len_split(&s[i], c) + 1) * sizeof(char));
			if (!tab[k])
				return (NULL);
			ft_strncpy(tab[k], &s[i], (ft_len_split(&s[i], c)));
			tab[k++][ft_len_split(&s[i], c)] = '\0';
			word = 1;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc((ft_number_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	ft_actual_split(s, c, tab);
	tab[ft_number_words(s, c)] = NULL;
	return (tab);
}
