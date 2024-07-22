/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:12:42 by dukim             #+#    #+#             */
/*   Updated: 2024/07/13 20:12:43 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	drop_triangle_bottom(t_deque *stack, t_deque *sa, t_deque *sb, unsigned int size)
{
	unsigned int	len;

	len = stack->len - size;
	if (len <= (stack->len) / 2)
	{
		while (len--)
			if (stack->name == 'A')
				command_cotroller(sa, sb, 7);	
			else
				command_cotroller(sa, sb, 8);
		return ;
	}
	while (size--)
		if (stack->name == 'A')
			command_cotroller(sa, sb, 5);	
		else
			command_cotroller(sa, sb, 6);
}

void	sort_3_triangle(t_deque *stack, t_deque *sa, t_deque *sb, unsigned int size, char is_max)
{
	if (is_sorted(stack, 3, is_max))
		return ;
	if (stack->name == 'A')
		command_cotroller(sa, sb, 5);	
	else
		command_cotroller(sa, sb, 6);
	if (is_swap(stack, is_max))
		if (stack->name == 'A')
			command_cotroller(sa, sb, 1);	
		else
			command_cotroller(sa, sb, 2);
	if (stack->name == 'A')
		command_cotroller(sa, sb, 7);	
	else
		command_cotroller(sa, sb, 8);
	if (is_sorted(stack, 3, is_max))
		return ;
	if (is_swap(stack, is_max))
		if (stack->name == 'A')
			command_cotroller(sa, sb, 1);	
		else
			command_cotroller(sa, sb, 2);
}

int	earlyreturn_sorted_stack(t_deque *sa, t_deque *sb, \
								unsigned int size, t_is is)
{
	int	i;

	if (is.is_a && is_sorted(sa, size, is.is_max))
	{
		if (!is.is_3)
			drop_triangle_bottom(sa, sa, sb, size);
		return (1);
	}
	if (!is.is_a && is_sorted(sa, size, is.is_max == 0))
	{
		i = size;
		while (i--)
			command_cotroller(sa, sb, 4);
		if (!is.is_3)
			drop_triangle_bottom(sb, sa, sb, size);
		return (1);
	}
	return (0);
}

static void	print_command(int cmd_num)
{
	if (cmd_num == 1)
		ft_putendl_fd("sa", 1);
	if (cmd_num == 2)
		ft_putendl_fd("sb", 1);
	if (cmd_num == 3)
		ft_putendl_fd("pa", 1);
	if (cmd_num == 4)
		ft_putendl_fd("pb", 1);
	if (cmd_num == 5)
		ft_putendl_fd("ra", 1);
	if (cmd_num == 6)
		ft_putendl_fd("rb", 1);
	if (cmd_num == 7)
		ft_putendl_fd("rra", 1);
	if (cmd_num == 8)
		ft_putendl_fd("rrb", 1);
}

void	command_cotroller(t_deque *sa, t_deque *sb, int cmd_num)
{
	static int	pre_cmd;

	if (cmd_num == 1)
		swap(sa);
	if (cmd_num == 2)
		swap(sb);
	if (cmd_num == 3)
		push(sa, sb);
	if (cmd_num == 4)
		push(sb, sa);
	if (cmd_num == 5)
		rotate(sa);
	if (cmd_num == 6)
		rotate(sb);
	if (cmd_num == 7)
		reverse_rotate(sa);
	if (cmd_num == 8)
		reverse_rotate(sb);
	if ((pre_cmd == 5 && cmd_num == 7) || (pre_cmd == 7 && cmd_num == 5) \
		|| (pre_cmd == 6 && cmd_num == 8) || (pre_cmd == 8 && cmd_num == 6))
	{
		pre_cmd = 0;
		return ;
	}
	if ((pre_cmd == 5 && cmd_num == 6) || (pre_cmd == 6 && cmd_num == 5) \
		|| (pre_cmd == 7 && cmd_num == 8) || (pre_cmd == 8 && cmd_num == 7))
	{
		
		if (pre_cmd <= 6)
			ft_putendl_fd("rr", 1);
		else
			ft_putendl_fd("rrr", 1);
		pre_cmd = 0;
		return ;
	}
	print_command(pre_cmd);
	if (pre_cmd && cmd_num)
		print_command(cmd_num);
	if (pre_cmd == 0)
		pre_cmd = cmd_num;
	else
		pre_cmd = 0;
}
