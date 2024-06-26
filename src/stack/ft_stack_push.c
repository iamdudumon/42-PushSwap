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

void	push(t_list *to, t_list **from)
{
	t_list	*temp;
	if (!(*from))
		return ;
	temp = (*from)->next;
	ft_lstadd_front(&to, *from);
	*from = temp;
}

