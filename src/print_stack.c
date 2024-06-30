/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:27:27 by dukim             #+#    #+#             */
/*   Updated: 2024/06/30 15:27:28 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void	print_stack(t_list *sa, t_list *sb)
{
	printf("--------------------------------\n");
	while (sa || sb)
	{
		if (!sa)
			printf(" \t\t%d\n", *(int *)(sb->content));
		else if (!sb)
			printf("%d\t\t \n", *(int *)(sa->content));
		else
			printf("%d\t\t%d\n", *(int *)(sa->content), *(int *)(sb->content));
		if (sa)
			sa = sa->next;
		if (sb)
			sb = sb->next;
	}
	printf("stack a\t\tstack b\n\n");
}

static int	exec_one_command(t_list *sa, t_list *sb, char *cmd)
{
	
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap(sa);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap(sb);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		swap_twin(sa, sb);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		push(&sa, &sb);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		push(&sb, &sa);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		rotate(sa);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rotate(sb);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rotate_twin(sa, sb);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		reverse_rotate(sa);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate(sb);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		reverse_rotate_twin(sa, sb);
	else
		return (1);
	print_stack(sa, sb);
	return (0);
}

int	exec_commands(t_list *sa, t_list *sb)
{
	char	*cmd;
	int		error;

	print_stack(sa, sb);
	while (1)
	{
		cmd = get_next_line(1);
		if (!cmd)
			return (0);
		error = exec_one_command(sa, sb, cmd);
		free(cmd);
		if (error)
			return (error);
	}
}
