/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:19:23 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/19 17:19:24 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/get_next_line.h"

static char			*ft_str_pre_n(char *str)
{
	int				i;
	char			*new_n;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	new_n = ft_strsub(str, 0, i);
	return (new_n);
}

static int			get_line(char **line, t_list **list)
{
	char			*p_tmp;
	char			*tmp;

	*line = ft_str_pre_n((*list)->content);
	p_tmp = ft_strchr((*list)->content, '\n');
	if (!p_tmp)
	{
		free((*list)->content);
		(*list)->content = NULL;
		return (1);
	}
	p_tmp++;
	tmp = ft_strdup(p_tmp);
	free((*list)->content);
	(*list)->content = tmp;
	return (1);
}

static t_list		*ft_se_i(const int fd, t_list **list)
{
	t_list			*tmp_list;

	if (!(*list))
	{
		*list = ft_lstnew(NULL, (size_t)fd);
		(*list)->content_size = fd;
		return (*list);
	}
	tmp_list = *list;
	while (tmp_list)
	{
		if (tmp_list->content_size == (size_t)fd)
			return (tmp_list);
		tmp_list = tmp_list->next;
	}
	tmp_list = ft_lstnew(NULL, (size_t)fd);
	tmp_list->content_size = fd;
	if (!tmp_list)
	{
		free(tmp_list->content);
		free(tmp_list);
	}
	return (*list);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list_i_fd;
	t_list			*tmp_fd;
	char			*tmp_;
	int				st;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || fd == 1 || read(fd, 0, 0) == -1)
		return (-1);
	tmp_fd = ft_se_i(fd, &list_i_fd);
	if (tmp_fd->content != '\0' && (ft_strchr(tmp_fd->content, '\n')))
		return (get_line(line, &tmp_fd));
	while ((st = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[st] = '\0';
		if (tmp_fd->content == '\0')
			tmp_fd->content = ft_strnew(st + 1);
		tmp_ = ft_strjoin(tmp_fd->content, buf);
		free(tmp_fd->content);
		tmp_fd->content = tmp_;
		if (ft_strchr(tmp_fd->content, '\n'))
			return (get_line(line, &tmp_fd));
	}
	if (tmp_fd->content != NULL && ft_strlen(tmp_fd->content) > 0)
		return (get_line(line, &tmp_fd));
	return ((st == 0) ? 0 : -1);
}
