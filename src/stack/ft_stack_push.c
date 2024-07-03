/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:26:17 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 17:26:18 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	push(t_deque *to, t_deque *from)
{
	t_list	*temp;

	if (!(from->header))
		return ;
	temp = from->header->next;
	ft_lstadd_front(&(to->header), from->header);
	from->header = temp;
	if (!from->header)
	{
		from->tail = 0;
		return ;
	}
	from->header->prev = 0;
	if (!from->header->next)
		from->tail = from->header;
}
