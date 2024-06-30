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

static int	is_sorted(t_list *sa)
{
	t_list	*ptr;

	ptr = sa;
	while (ptr->next)
	{
		if (*(int *)(ptr->content) > *(int *)(ptr->next->content))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static int	exec_command(t_list **sa, t_list **sb, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap(*sa);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap(*sb);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		swap_twin(*sa, *sb);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		push(sa, sb);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		push(sb, sa);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		rotate(*sa);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rotate(*sb);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rotate_twin(*sa, *sb);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		reverse_rotate(*sa);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate(*sb);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		reverse_rotate_twin(*sa, *sb);
	else
		return (1);
	print_stack(*sa, *sb);	
	return (0);
}

void	check_sorted(t_list **sa, t_list **sb)
{
	char	*cmd;

	print_stack(*sa, *sb);
	while (1)
	{
		cmd = get_next_line(1);
		if (!cmd)
			break ;
		if (exec_command(sa, sb, cmd))
		{
			free(cmd);
			ft_putstr_fd("Error\n", 1);
			return ;
		}
		free(cmd);
	}
	if (is_sorted(*sa) && !(*sb))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
