/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:26:53 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 17:26:54 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	rotate(t_deque *stack)
{
	t_list	*last;
	t_list	*ptr;
	int		*temp1;
	int		*temp2;

	if (!stack->header)
		return ;
	last = stack->tail;
	ptr = last;
	temp1 = ptr->content;
	while (ptr->prev)
	{
		temp2 = ptr->prev->content;
		ptr->prev->content = temp1;
		temp1 = temp2;
		ptr = ptr->prev;
	}
	last->content = temp1;
}

// void	rotate_twin(t_deque *sa, t_deque *sb)
// {
// 	rotate(sa, "");
// 	rotate(sb, "");
// 	ft_putstr_fd("rr\n", 1);
// }
