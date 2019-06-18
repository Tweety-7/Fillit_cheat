/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:06:30 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/11 19:15:14 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/fillit.h"
#include "head/get_next_line.h"

int			ft_valid_map(char **fig)
{
	int		i;
	int		j;
	int		s;

	i = 0;
	s = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((int)fig[i][j] != '.' && (int)fig[i][j] == '#')
				s++;
			j++;
		}
		i++;
	}
	if (s != 4)
	{
		while (--i >= 0)
			free(fig[i]);
		free(fig);
		return (-1);
	}
	return (1);
}

int			ft_valid_big(int fig6[6][6])
{
	int		i;
	int		j;
	int		s;

	i = 0;
	s = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
			if (fig6[i][j] == 1)
				s = s + fig6[i - 1][j] + fig6[i + 1][j] +
				fig6[i][j - 1] + fig6[i][j + 1];
	}
	if (s == 6 || s == 8)
		return (1);
	return (-1);
}

int			ft_valid_fig_6_8(int fig[4][4])
{
	int		i;
	int		j;
	int		fig6[6][6];

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			fig6[i][j] = 0;
			if (fig[i - 1][j - 1] == 1)
				fig6[i][j] = 1;
		}
	}
	i = 0;
	j = 0;
	while (i <= 5 && j <= 5)
	{
		fig6[i][0] = 0;
		fig6[i++][5] = 0;
		fig6[0][j] = 0;
		fig6[5][j++] = 0;
	}
	return (ft_valid_big(fig6));
}

int			ft_list_fig(char **fig)
{
	int		fig_int[4][4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			fig_int[i][j] = (int)fig[i][j] == '#' ? 1 : 0;
			j++;
		}
		i++;
	}
	if (ft_valid_fig_6_8(fig_int) == 1)
		return (1);
	while (--i >= 0)
		free(fig[i]);
	free(fig);
	return (-1);
}

int			free_fig(int i, char **fig, int st, int f)
{
	if (i == 0 || st == 0)
	{
		while (--i >= 0)
			free(fig[i]);
		free(fig);
		return ((i != 0 || st != 0) ? -1 : f - 1);
	}
	while (--i >= 0)
		free(fig[i]);
	free(fig);
	return (-1);
}
