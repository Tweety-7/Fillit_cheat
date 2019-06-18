/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_fillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:45:00 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/11 19:12:19 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/fillit.h"

static int		ft_map_1(t_map *map, t_fig figa, int i, int j)
{
	int			c;
	int			no;

	c = 0;
	no = 0;
	while (no < 4)
	{
		if ((figa.x[no] + i) < map->size && (figa.y[no] + j) < map->size &&
			map->mapc[figa.x[no] + i][figa.y[no] + j] == '.')
		{
			map->mapc[figa.x[no] + i][figa.y[no] + j] = figa.name;
			c++;
		}
		no++;
	}
	if (c == 4)
		return (1);
	no = -1;
	while (no++ < 4)
		if ((figa.x[no] + i) < map->size && (figa.y[no] + j) < map->size &&
			map->mapc[figa.x[no] + i][figa.y[no] + j] == figa.name)
			map->mapc[figa.x[no] + i][figa.y[no] + j] = '.';
	return (0);
}

static void		ft_free_last_map(t_map *map, t_fig figa, int i, int j)
{
	int			no;

	no = 0;
	while (no < 4)
	{
		if ((figa.x[no] + i) < map->size && (figa.y[no] + j) < map->size &&
			map->mapc[figa.x[no] + i][figa.y[no] + j] == figa.name)
			map->mapc[figa.x[no] + i][figa.y[no] + j] = '.';
		no++;
	}
}

static t_map	*ft_free_and_new(t_map **map)
{
	int			i;
	int			size;

	size = (*map)->size + 1;
	i = 0;
	while (i < size - 1)
		free((*map)->mapc[i++]);
	free((*map)->mapc);
	free(*map);
	*map = (ft_empty_map(size));
	return (*map);
}

int				ft_map_rec(t_fig *figi, t_map **map)
{
	static int	count_fig = -1;
	int			i;
	int			j;

	i = -1;
	if (figi[0].n == ++count_fig)
		return (1);
	if (count_fig < figi[0].n)
	{
		while (++i < (*map)->size && (j = -1))
			while (++j < (*map)->size)
				if (ft_map_1(*map, figi[count_fig], i, j) == 1)
				{
					if (ft_map_rec(figi, map))
						return (1);
					ft_free_last_map(*map, figi[count_fig], i, j);
				}
	}
	if (--count_fig == -1)
	{
		*map = ft_free_and_new(map);
		ft_map_rec(figi, map);
	}
	return (0);
}
