/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:46:42 by dukim             #+#    #+#             */
/*   Updated: 2024/07/13 16:46:50 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static t_list	*get_max_node3(t_list *node1, t_list *node2, t_list *node3, t_size ts)
{
	int	v1;
	int	v2;
	int	v3;

	if (!ts.s1)
		v1 = -2147483648;
	else
		v1 = *((int *)(node1->content));
	if (!ts.s2)
		v2 = -2147483648;
	else
		v2 = *((int *)(node2->content));
	if (!ts.s3)
		v3 = -2147483648;
	else
		v3 = *((int *)(node3->content));
	if (v2 < v1 && v1 > v3)
		return (node1);
	if (v1 < v2 && v2 > v3)
		return (node2);
	return (node3);
}

static t_list	*get_min_node3(t_list *node1, t_list *node2, t_list *node3, t_size ts)
{
	int	v1;
	int	v2;
	int	v3;

	if (!ts.s1)
		v1 = 2147483647;
	else
		v1 = *((int *)(node1->content));
	if (!ts.s2)
		v2 = 2147483647;
	else
		v2 = *((int *)(node2->content));
	if (!ts.s3)
		v3 = 2147483647;
	else
		v3 = *((int *)(node3->content));
	if (v2 > v1 && v1 < v3)
		return (node1);
	if (v1 > v2 && v2 < v3)
		return (node2);
	return (node3);
}

t_list	*get_node3(t_deque *s1, t_deque *s2, t_size ts, int is_max)
{
    if (is_max)
        return (get_max_node3(s1->tail, s2->tail, s1->header, ts));
    return (get_min_node3(s1->tail, s2->tail, s1->header, ts));
}

int	is_sorted(t_deque *sa)
{
	t_list	*ptr;

	ptr = sa->header;
	while (ptr->next)
	{
		if (*(int *)(ptr->content) > *(int *)(ptr->next->content))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
