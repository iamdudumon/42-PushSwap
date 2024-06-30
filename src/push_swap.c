/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:38:58 by dukim             #+#    #+#             */
/*   Updated: 2024/06/27 12:38:59 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int	is_sorted(t_list *sa)
{
	t_list  *ptr;
	int		prev_content;

	ptr = sa->next;
	prev_content = *(int *)(sa->content);
	while (ptr->next)
	{
		if (*(int *)(sa->content) < prev_content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	push_swap(t_list *sa, t_list *sb, int size)
{

}