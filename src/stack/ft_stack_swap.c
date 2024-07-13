/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:26:37 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 17:26:39 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	swap(t_deque *stack)
{
	int	*temp;

	if (!stack->header || !stack->header->next)
		return ;
	temp = stack->header->content;
	stack->header->content = stack->header->next->content;
	stack->header->next->content = temp;
	if (stack->name == 'A')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

// void	swap_twin(t_deque *as, t_deque *bs)
// {
// 	swap(as, "");
// 	swap(bs, "");
// 	ft_putstr_fd("ss\n", 1);
// }
