/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:46:50 by dukim             #+#    #+#             */
/*   Updated: 2024/07/13 16:46:52 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int	is_swap(t_deque *stack, int is_max)
{
	int	head;
	int	head_next;

	head = *(int *)(stack->header->content);
	head_next = *(int *)(stack->header->next->content);
	if (is_max)
	{
		if (head_next < head)
			return (1);
		return (0);
	}
	if (head_next > head)
		return (1);
	return (0);
}

t_size	cal_size3(int size)
{
	t_size	ts;
	int		c;

	c = size % 3;
	if (c == 0)
		c = 0;
	else
		c -= 1;
	ts.s2 = size - (2 * (size / 3) + c);
	ts.s1 = size - ts.s2 - ((size - ts.s2) / 2);
	ts.s3 = size - ts.s1 - ts.s2;
	return (ts);
}

t_is	is_return(t_is is, int n)
{
	if (n == 1)
	{
		is.is_a = is.is_a == 0;
		is.is_3 = 0;
	}
	if (n == 2)
		is.is_3 = 0;
	if (n == 3)
	{
		is.is_max = is.is_max == 0;
		is.is_a = is.is_a == 0;
		is.is_3 = 1;
	}
	return (is);
}
