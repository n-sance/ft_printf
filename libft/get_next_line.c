/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:02:01 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:36:56 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd_list	*create_node(int fd)
{
	t_fd_list	*new;

	new = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->fd_str = ft_strnew(0);
	if (!new->fd_str)
		return (NULL);
	new->tmp = NULL;
	new->next = NULL;
	return (new);
}

static t_fd_list	*find_node_by_fd(const int needed_fd, t_fd_list *fd_list)
{
	t_fd_list	*ptr;

	ptr = fd_list;
	if (!fd_list || (ptr->fd == needed_fd))
		return (ptr);
	while (ptr->next != NULL)
	{
		if (ptr->fd == needed_fd)
			return (ptr);
		ptr = ptr->next;
	}
	ptr->next = create_node(needed_fd);
	return (ptr->next);
}

static int			split_str_by_newline(t_fd_list *cur_node, char **line)
{
	char	*pos;

	if (ft_strlen(cur_node->fd_str) == 0)
		return (0);
	pos = ft_strchr(cur_node->fd_str, '\n');
	if (pos == NULL)
	{
		*line = ft_strdup(cur_node->fd_str);
		free(cur_node->fd_str);
		cur_node->fd_str = ft_strnew(0);
		return (((*line) == NULL) ? (-1) : (1));
	}
	pos[0] = '\0';
	*line = ft_strdup(cur_node->fd_str);
	cur_node->tmp = cur_node->fd_str;
	cur_node->fd_str = ft_strdup(&(pos[1]));
	free(cur_node->tmp);
	return (((*line) == NULL || cur_node->fd_str == NULL) ? (-1) : (1));
}

int					get_next_line(const int fd, char **line)
{
	int					ret;
	char				read_buf[BUFF_SIZE + 1];
	static	t_fd_list	*fd_list;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	fd_list = (fd_list == NULL) ? create_node(fd) : fd_list;
	while (!ft_strchr(NODE->fd_str, '\n'))
	{
		ret = read(fd, read_buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (split_str_by_newline(NODE, line));
		read_buf[ret] = '\0';
		NODE->tmp = NODE->fd_str;
		NODE->fd_str = ft_strjoin(NODE->fd_str, read_buf);
		free(NODE->tmp);
	}
	return (split_str_by_newline(NODE, line));
}
