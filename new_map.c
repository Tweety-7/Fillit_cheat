/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:36:34 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/12 18:40:21 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/fillit.h"

static int		ft_min_4(int x, int x2, int x3, int x4)
{
	int			min;

	min = x;
	if (x2 < min)
		min = x2;
	if (x3 < min)
		min = x3;
	if (x4 < min)
		min = x4;
	return (min);
}

static t_fig	ft_min_0(t_fig figa, int n, int f)
{
	int			min_x;
	int			min_y;
	int			i;

	min_x = ft_min_4(figa.x[0], figa.x[1], figa.x[2], figa.x[3]);
	min_y = ft_min_4(figa.y[0], figa.y[1], figa.y[2], figa.y[3]);
	i = 0;
	while (i < 4)
	{
		figa.x[i] = figa.x[i] - min_x;
		figa.y[i] = figa.y[i] - min_y;
		i++;
	}
	figa.n = n;
	figa.name = 'A' + f;
	return (figa);
}

static t_fig	ft_i_j_n(int i, int j, int no, t_fig *figa)
{
	figa->x[no] = i;
	figa->y[no++] = j;
	return (*figa);
}

t_fig			*ft_mas_fig(int n, int fd, int f)
{
	t_fig		*figi;
	int			i;
	int			j;
	int			no;
	char		*line;

	figi = (t_fig*)malloc(sizeof(t_fig) * n);
	while ((i = -1) && ++f < n)
	{
		no = f == 0 ? 0 : get_next_line(fd, &line) - 1;
		if (f != 0)
			free(line);
		while ((j = -1) && ++i < 4)
		{
			get_next_line(fd, &line);
			while (++j < 4)
				if (line[j] == '#')
					figi[f] = ft_i_j_n(i, j, no++, &figi[f]);
			free(line);
		}
		figi[f] = ft_min_0(figi[f], n, f);
	}
	return (figi);
}

int				ft_sqrt(int nb)
{
	int			i;

	i = 1;
	if (i <= nb)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}
