/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:32:10 by dukim             #+#    #+#             */
/*   Updated: 2024/08/06 17:32:12 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap_bonus.h"

static int	is_sorted(t_deque *stack, unsigned int size, char is_max)
{
	t_list	*ptr;

	ptr = stack->header;
	while (ptr->next && size--)
	{
		if (is_max && *(int *)(ptr->content) > *(int *)(ptr->next->content))
			return (0);
		if (!is_max && *(int *)(ptr->content) < *(int *)(ptr->next->content))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static int	exec_command(t_deque *sa, t_deque *sb, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap(sa);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap(sb);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		twin_swap(sa, sb);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		push(sa, sb);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		push(sb, sa);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		rotate(sa);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rotate(sb);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		twin_rotate(sa, sb);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		reverse_rotate(sa);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate(sb);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		twin_reverse_rotate(sa, sb);
	else
		return (0);
	return (1);
}

void	check_sorted(t_deque *sa, t_deque *sb)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(1);
		if (!cmd)
			break ;
		if (!exec_command(sa, sb, cmd))
		{
			free(cmd);
			ft_putendl_fd("Error", 1);
			return ;
		}
		free(cmd);
	}
	if (is_sorted(sa, sa->len, 1))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
