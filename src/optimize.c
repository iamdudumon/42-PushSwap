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
				command_cotroller(sa, sb, "rra");	
			else
				command_cotroller(sa, sb, "rrb");
		return ;
	}
	while (size--)
		if (stack->name == 'A')
			command_cotroller(sa, sb, "ra");	
		else
			command_cotroller(sa, sb, "rb");
}

void	sort_3_triangle(t_deque *stack, t_deque *sa, t_deque *sb, unsigned int size, char is_max)
{
	if (is_sorted(stack, 3, is_max))
		return ;
	if (stack->name == 'A')
		command_cotroller(sa, sb, "ra");	
	else
		command_cotroller(sa, sb, "rb");
	if (is_swap(stack, is_max))
		if (stack->name == 'A')
			command_cotroller(sa, sb, "sa");	
		else
			command_cotroller(sa, sb, "sb");
	if (stack->name == 'A')
		command_cotroller(sa, sb, "rra");	
	else
		command_cotroller(sa, sb, "rrb");
	if (is_sorted(stack, 3, is_max))
		return ;
	if (is_swap(stack, is_max))
		if (stack->name == 'A')
			command_cotroller(sa, sb, "sa");	
		else
			command_cotroller(sa, sb, "sb");
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
			command_cotroller(sa, sb, "pb");
		if (!is.is_3)
			drop_triangle_bottom(sb, sa, sb, size);
		return (1);
	}
	return (0);
}

void	command_cotroller(t_deque *sa, t_deque *sb, char *cmd)
{
	static int	pre_cmd;
	int	cur_cmd;

	cur_cmd =0;
	if (!ft_strncmp(cmd, "sa", 2))
	{
		swap(sa);
		cur_cmd = 1;
	}
	else if (!ft_strncmp(cmd, "sb", 2))
	{	
		swap(sb);
		cur_cmd = 2;
	}
	else if (!ft_strncmp(cmd, "pa", 2))
	{
		push(sa, sb);
		cur_cmd = 3;
	}
	else if (!ft_strncmp(cmd, "pb", 2))
	{
		push(sb, sa);
		cur_cmd = 4;
	}
	else if (!ft_strncmp(cmd, "ra", 2))
	{
		rotate(sa);
		cur_cmd = 5;
	}
	else if (!ft_strncmp(cmd, "rb", 2))
	{
		rotate(sb);
		cur_cmd = 6;
	}
	else if (!ft_strncmp(cmd, "rra", 3))
	{
		reverse_rotate(sa);
		cur_cmd = 7;
	}
	else if (!ft_strncmp(cmd, "rrb", 3))
	{
		reverse_rotate(sb);
		cur_cmd = 8;
	}

	if ((pre_cmd == 5 && cur_cmd == 7) || (pre_cmd == 7 && cur_cmd == 5) \
		|| (pre_cmd == 6 && cur_cmd == 8) || (pre_cmd == 8 && cur_cmd == 6))
	{
		pre_cmd = 0;
		return ;
	}
	if ((pre_cmd == 5 && cur_cmd == 6) || (pre_cmd == 6 && cur_cmd == 5))
	{
		pre_cmd = 0;
		ft_putendl_fd("rr", 1);
		return ;
	}
	if ((pre_cmd == 7 && cur_cmd == 8) || (pre_cmd == 8 && cur_cmd == 7))
	{
		pre_cmd = 0;
		ft_putendl_fd("rrr", 1);
		return ;
	}
	if (pre_cmd == 1)
		ft_putendl_fd("sa", 1);
	if (pre_cmd == 2)
		ft_putendl_fd("sb", 1);
	if (pre_cmd == 3)
		ft_putendl_fd("pa", 1);
	if (pre_cmd == 4)
		ft_putendl_fd("pb", 1);
	if (pre_cmd == 5)
		ft_putendl_fd("ra", 1);
	if (pre_cmd == 6)
		ft_putendl_fd("rb", 1);
	if (pre_cmd == 7)
		ft_putendl_fd("rra", 1);
	if (pre_cmd == 8)
		ft_putendl_fd("rrb", 1);
	if (pre_cmd && cur_cmd)
		ft_putendl_fd(cmd, 1);
	if (pre_cmd == 0)
		pre_cmd = cur_cmd;
	else
		pre_cmd = 0;
}
