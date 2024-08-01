/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:54:25 by dukim             #+#    #+#             */
/*   Updated: 2024/07/29 20:54:26 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	exec_s1_tail(t_deque *s1, t_deque *s2)
{
	if (s1->name == 'A')
	{
		command_cotroller(s1, s2, 7);
		command_cotroller(s1, s2, 4);
	}
	else
	{
		command_cotroller(s2, s1, 8);
		command_cotroller(s2, s1, 3);
	}
}

void	exec_s2_tail(t_deque *s1, t_deque *s2)
{
	if (s1->name == 'A')
		command_cotroller(s1, s2, 8);
	else
		command_cotroller(s2, s1, 7);
}

void	exec_s1_head(t_deque *s1, t_deque *s2)
{
	if (s1->name == 'A')
		command_cotroller(s1, s2, 4);
	else
		command_cotroller(s2, s1, 3);
}
