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

static char	*ft_gnl_read_buffer(t_gnl	*node)
{
	char	*buf;
	ssize_t	size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	size = read(node->fd, buf, BUFFER_SIZE);
	if (size == -1)
	{
		free(buf);
		return (0);
	}
	buf[size] = '\0';
	return (buf);
}

static char	*ft_gnl_split_buffer(char *buf, char **backup)
{
	char	*res;

	res = ft_gnl_strjoin(*backup, buf, '\0');
	free(*backup);
	*backup = 0;
	if (*res == '\0')
	{
		free(res);
		return (0);
	}
	if (!ft_gnl_get_chridx(res, '\n'))
	{
		if (*buf == '\0')
			return (res);
		*backup = res;
		return (0);
	}
	buf = ft_gnl_strjoin("", res, '\n');
	*backup = ft_gnl_strjoin(ft_gnl_get_chridx(res, '\n') + 1, 
																										"", '\0');
	free(res);
	return (buf);
}

static char	*ft_gnl_get_one_line(t_gnl *node)
{
	char	*buf;
	char	*res;

	while (1)
	{
		buf = ft_gnl_read_buffer(node);
		if (!buf)
			return (0);
		res = ft_gnl_split_buffer(buf, &(node->backup));
		free(buf);
		if (!res &&!(node->backup))
			return (0);
		if (res)
			break ;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static t_gnl	*list;
	t_gnl			*node;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
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
	res = ft_gnl_get_one_line(node);
	if (!res)
		ft_gnl_del_node(&list, node);
	return (res);
}
