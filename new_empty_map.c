/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_empty_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:43:27 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/11 19:12:36 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/fillit.h"

t_map		*ft_empty_map(int size)
{
	int		i;
	int		j;
	char	**str;
	t_map	*map;

	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	str = (char**)malloc(sizeof(char*) * size);
	while (i < size)
	{
		j = 0;
		str[i] = (char*)malloc(sizeof(char) * (size + 1));
		str[i][size] = '\0';
		while (j < size)
		{
			str[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
	map->mapc = str;
	map->size = size;
	return (map);
}

static int	ft_valid_a(int fd, char *buf, int f, char **fig)
{
	int		i;
	int		st;

	i = 0;
	while (i < 4)
	{
		if ((st = read(fd, buf, 4) != 4))
			return (free_fig(i, fig, st, f));
		buf[4] = '\0';
		fig[i++] = ft_strdup(buf);
		st = read(fd, buf, 1);
		if (buf[0] != '\n')
			return (free_fig(i, fig, st, f));
	}
	if (ft_valid_map(fig) == -1 || ft_list_fig(fig) == -1)
		return (-1);
	while (--i >= 0)
		free(fig[i]);
	return (st);
}

int			ft_valid_gnl(const int fd, int f)
{
	int		st;
	char	**fig;
	char	buf[5];

	st = 1;
	fig = (char**)malloc(sizeof(char*) * 4);
	while (st > 0)
	{
		if (f++ && ((st = read(fd, buf, 1)) == 0 || buf[0] != '\n'))
		{
			free(fig);
			return (st == 0 ? f - 1 : -1);
		}
		if ((st = ft_valid_a(fd, buf, f, fig)) == -1)
			return (-1);
	}
	return (f - 1);
}
