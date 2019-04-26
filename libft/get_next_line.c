/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboissel <tboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:15:14 by tboissel          #+#    #+#             */
/*   Updated: 2018/05/22 14:44:43 by tboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_c_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

int		ft_read_gnl(int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (*str && ft_c_in_str(*str, '\n'))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (*str)
			*str = ft_strjoinfree(*str, buf);
		else
			*str = ft_strdup(buf);
		if (ft_c_in_str(*str, '\n'))
			break ;
		if (!fd && ret < BUFF_SIZE)
			break ;
	}
	return (ret);
}

int		ft_fill_line(char *str, char **line)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i == 0)
		*line = ft_strnew(1);
	else
		*line = ft_strsub(str, 0, i);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	int				i;
	char			*tmp;
	int				ret;

	if (fd < 0 || !line || (ret = ft_read_gnl(fd, &str)) == -1)
		return (-1);
	if ((ft_strlen(str) == 0) && (ret == 0) && (*line = ft_strnew(1)))
		return (0);
	i = ft_fill_line(str, line);
	tmp = str;
	str = ft_strdup(str + i + !(!str[i]));
	if (!ft_strlen(*line) && !ft_strlen(str) && tmp[i] != '\n'
	&& (!fd || !ft_read_gnl(fd, &str)))
	{
		str = NULL;
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
