/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:12:42 by dukim             #+#    #+#             */
/*   Updated: 2024/07/13 20:12:43 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	drop_triangle_bottom(t_deque *stack, unsigned int size)
{
	unsigned int	len;

	len = stack->len - size;
	if (len <= (stack->len) / 2)
	{
		while (len--)
			reverse_rotate(stack);
		return ;
	}
	while (size--)
		rotate(stack);
}

void	sort_3_triangle(t_deque *stack, unsigned int size, char is_max)
{
	if (is_sorted(stack, 3, is_max))
		return ;
	rotate(stack);
	if (is_swap(stack, is_max))
		swap(stack);
	reverse_rotate(stack);
	if (is_sorted(stack, 3, is_max))
		return ;
	if (is_swap(stack, is_max))
		swap(stack);
}

int	earlyreturn_sorted_stack(t_deque *sa, t_deque *sb, \
								unsigned int size, t_is is)
{
	int	i;

	if (is.is_a && is_sorted(sa, size, is.is_max))
	{
		if (!is.is_3)
			drop_triangle_bottom(sa, size);
		return (1);
	}
	if (!is.is_a && is_sorted(sa, size, is.is_max == 0))
	{
		i = size;
		while (i--)
			push(sb, sa);
		if (!is.is_3)
			drop_triangle_bottom(sb, size);
		return (1);
	}
	return (0);
}
