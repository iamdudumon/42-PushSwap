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
}

void	twin_swap(t_deque *sa, t_deque *sb)
{
	swap(sa);
	swap(sb);
}
