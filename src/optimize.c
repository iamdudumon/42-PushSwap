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
	unsigned int    len;

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
