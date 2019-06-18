/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_l_sq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:32:18 by kwalter           #+#    #+#             */
/*   Updated: 2019/06/11 19:13:04 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/fillit.h"

int		ft_max_4(int x, int x2, int x3, int x4)
{
	int	max;

	max = x;
	if (x2 > max)
		max = x2;
	if (x3 > max)
		max = x3;
	if (x4 > max)
		max = x4;
	return (max);
}

int		l_sq(int sq, int max)
{
	int	l_sq;

	l_sq = 2;
	while (1)
	{
		if (sq <= l_sq * l_sq && max <= l_sq * l_sq)
			return (l_sq);
		l_sq++;
	}
}

int		ft_min_l_sq(int n, t_fig *fig)
{
	int	sq;
	int	max_x;
	int	max_y;
	int	i;

	i = 0;
	max_x = 0;
	max_y = 0;
	while (i < n)
	{
		max_x = max_x + (ft_max_4(fig[i].x[0], fig[i].x[1], fig[i].x[2],
		fig[i].x[3]) + 1);
		max_y = max_y + (ft_max_4(fig[i].y[0], fig[i].y[1], fig[i].y[2],
		fig[i].y[3]) + 1);
		i++;
	}
	sq = n * 4;
	if (n >= 8 && (max_y == n * 4 || max_x == n * 4))
		return (8);
	if (sq < 48)
		return (ft_sqrt(sq));
	return (l_sq(sq, (max_x + max_y)));
}
