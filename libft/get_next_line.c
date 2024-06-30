/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:34:12 by dukim             #+#    #+#             */
/*   Updated: 2024/06/28 13:34:14 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_buffer(t_gnl_list	*node)
{
	char	*buf;
	char	*res;
	ssize_t	size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(node->fd, buf, BUFFER_SIZE);
	buf[size] = '\0';
	res = ft_gnl_strjoin(node->backup, buf, '\0');
	free(node->backup);
	free(buf);
	if (!ft_gnl_get_chridx(res, '\n'))
	{
		if (size == 0)
		{
			node->backup = 0;
			return (res);
		}
		node->backup = res;
		return (0);
	}
	buf = ft_gnl_strjoin("", res, '\n');
	node->backup = ft_gnl_strjoin(ft_gnl_get_chridx(res, '\n') + 1, "", '\0');
	free(res);
	return (buf);
}

static char	*get_one_line(t_gnl_list *node)
{
	char	*buf;

	buf = read_buffer(node);
	while (!buf)
		buf = read_buffer(node);
	if (*buf == '\0' && !(node->backup))
	{
		free(buf);
		return (0);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	t_gnl_list			*node;
	char				*res;

	node = list;
	while (node)
	{
		if (node->fd == fd)
			break ;
		node = node->next;
	}
	if (!node)
	{
		node = ft_gnl_lstnew(fd);
		ft_gnl_lstadd_back(&list, node);
	}
	res = get_one_line(node);
	if (!res)
		ft_gnl_del_node(&list, node);
	return (res);
}
