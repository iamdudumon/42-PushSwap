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
	t_list	*temp1;
	t_list	*temp2;

	if (!from->header)
		return ;
	if (to->name == 'A')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
	temp1 = to->header;
	temp2 = from->header->next;
	to->header = from->header;
	to->header->next = temp1;
	if (temp1)
		temp1->prev = to->header;
	from->header = temp2;
	if (from->header)
		from->header->prev = 0;
	else
		from->tail = 0;
	if (!to->tail)
		to->tail = to->header;
	to->len++;
	from->len--;
}
