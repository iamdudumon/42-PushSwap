/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:39:39 by dukim             #+#    #+#             */
/*   Updated: 2024/03/06 22:54:41 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstadd_back(t_list **header, t_list **tail, t_list *new)
// {
// 	if (!(*header) && !(*tail))
// 	{
// 		*header = new;
// 		*tail = new;
// 		return ;
// 	}
// 	if (!header || !tail || !new)
// 		return ;
// 	(*tail)->next = new;
// 	new->prev = *tail;
// 	*tail = new;
// }
void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}
