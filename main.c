/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:10:54 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/12 18:38:27 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head/fillit.h"

static void		free_fig_map(t_map **map)
{
	int			i;

	i = 0;
	while (i < (*map)->size)
		free((*map)->mapc[i++]);
	free((*map)->mapc);
	free(*map);
}

static int		ft_erorr(void)
{
	ft_putstr("error\n");
	return (0);
}

static void		ft_print_map(t_map **map)
{
	int			i;

	i = 0;
	while (i < ((*map)->size))
	{
		ft_putstr((*map)->mapc[i++]);
		ft_putstr("\n");
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	int			c_fig;
	t_fig		*figi;
	t_map		*map;
	int			i;

	if (argc == 2 && !(i = 0))
	{
		fd = open(argv[1], O_RDONLY);
		if ((c_fig = ft_valid_gnl(fd, 0)) == -1 || c_fig > 26 || c_fig < 1)
			return (ft_erorr());
		close(fd);
		fd = open(argv[1], O_RDONLY);
		figi = ft_mas_fig(c_fig, fd, -1);
		map = ft_empty_map(ft_min_l_sq(c_fig, figi));
		ft_map_rec(figi, &map);
		ft_print_map(&map);
		free_fig_map(&map);
		free(figi);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
