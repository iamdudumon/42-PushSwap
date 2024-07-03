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

void	rotate(t_deque *stack, char *cmd)
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
	if (*cmd != '\0')
		ft_putstr_fd(cmd, 1);
}

void	rotate_twin(t_deque *as, t_deque *bs)
{
	rotate(as, "");
	rotate(bs, "");
	ft_putstr_fd("rr\n", 1);
}
