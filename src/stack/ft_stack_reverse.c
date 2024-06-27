/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:26:32 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 17:26:34 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	reverse_rotate(t_list *stack)
{
    t_list  *ptr;
	int		*temp1;
	int		*temp2;

    ptr = stack;
	temp1 = ptr->content;
	while (ptr->next)
	{
		temp2 = ptr->next->content;
		ptr->next->content = temp1;
		temp1 = temp2;
        ptr = ptr->next;
	}
    stack->content = temp1;
}

void    reverse_rotate_twin(t_list *as, t_list *bs)
{
    reverse_rotate(as);
    reverse_rotate(bs);
}
