/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:34:21 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/09 17:10:33 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_fig
{
	char		name;
	int			x[4];
	int			y[4];
	int			n;
}				t_fig;

typedef struct	s_map
{
	int			size;
	char		**mapc;
}				t_map;

int				ft_sqrt(int nb);
int				ft_valid_map(char **fig);
int				ft_valid_big(int fig6[6][6]);
int				ft_valid_fig_6_8(int fig[4][4]);
int				ft_list_fig(char **fig);
int				ft_valid_gnl(const int fd, int f);
t_fig			*ft_mas_fig(int n, int fd, int f);
t_map			*ft_empty_map(int size);
int				ft_min_l_sq(int n, t_fig *fig);
int				ft_map_rec(t_fig *figi, t_map **map);
int				free_fig(int i, char **fig, int st, int f);
int				ft_max_4(int x, int x2, int x3, int x4);
int				ft_min_l_sq(int n, t_fig *fig);
int				l_sq(int sq, int max);

#endif
