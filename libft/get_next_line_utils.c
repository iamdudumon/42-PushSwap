/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:34:19 by dukim             #+#    #+#             */
/*   Updated: 2024/06/28 13:34:20 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_get_chridx(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_gnl_strjoin(char *s1, char *s2, char end)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1)
		s1 = "";
	s1_len = (size_t)(ft_gnl_get_chridx(s1, '\0') - s1);
	s2_len = (size_t)(ft_gnl_get_chridx(s2, end) - s2);
	if (end == '\n')
		s2_len++;
	join_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join_str)
		return (0);
	i = -1;
	while (++i < s1_len)
		join_str[i] = s1[i];
	while (++i - 1 < s1_len + s2_len)
		join_str[i - 1] = s2[i - 1 - s1_len];
	join_str[s1_len + s2_len] = '\0';
	return (join_str);
}

void	ft_gnl_lstadd_back(t_gnl **list, t_gnl *new)
{
	t_gnl	*tail;

	if (!(*list))
	{
		*list = new;
		tail = *list;
		return ;
	}
	if (!list || !new)
		return ;
	tail = *list;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
	tail->next->prev = tail;
	tail = tail->next;
}

t_gnl	*ft_gnl_lstnew(int fd)
{
	t_gnl	*node;

	node = (t_gnl *)malloc(sizeof(t_gnl) * 1);
	if (!node)
		return (0);
	node->fd = fd;
	node->backup = 0;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	ft_gnl_del_node(t_gnl **list, t_gnl *node)
{
	if (!(node->prev) && !(node->next))
	{
		free((node)->backup);
		free(node);
		*list = 0;
		return ;
	}
	if (!(node->next))
		node->prev->next = 0;
	if (!(node->prev))
	{
		node->next->prev = 0;
		*list = node->next;
	}
	if ((node->prev) && (node->next))
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node->backup);
	free(node);
}
