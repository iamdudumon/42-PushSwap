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

#include "../../inc/ft_push_swap.h"

void	drop_triangle_bottom(t_deque *stack, unsigned int size)
{
	unsigned int	len;

	len = stack->len - size;
	if (len <= (stack->len) / 2)
	{
		while (len--)
		{
			if (stack->name == 'A')
				command_cotroller(stack, 0, 7);
			else
				command_cotroller(0, stack, 8);
		}
		return ;
	}
	while (size--)
	{
		if (stack->name == 'A')
			command_cotroller(stack, 0, 5);
		else
			command_cotroller(0, stack, 6);
	}
}

void	sort_3_triangle(t_deque *stack, char is_max)
{
	if (is_sorted(stack, 3, is_max))
		return ;
	if (stack->name == 'A')
		command_cotroller(stack, 0, 5);
	else
		command_cotroller(0, stack, 6);
	if (is_swap(stack, is_max) && stack->name == 'A')
		command_cotroller(stack, 0, 1);
	if (is_swap(stack, is_max) && stack->name == 'B')
		command_cotroller(0, stack, 2);
	if (stack->name == 'A')
		command_cotroller(stack, 0, 7);
	else
		command_cotroller(0, stack, 8);
	if (is_sorted(stack, 3, is_max))
		return ;
	if (is_swap(stack, is_max) && stack->name == 'A')
		command_cotroller(stack, 0, 1);
	if (is_swap(stack, is_max) && stack->name == 'B')
		command_cotroller(0, stack, 2);
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
			command_cotroller(sa, sb, 4);
		if (!is.is_3)
			drop_triangle_bottom(sb, size);
		return (1);
	}
	return (0);
}
