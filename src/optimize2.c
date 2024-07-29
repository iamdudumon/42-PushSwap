/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:51:20 by dukim             #+#    #+#             */
/*   Updated: 2024/07/29 15:51:21 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static int	optimize_rotate_cmd(int pre_cmd, int cur_cmd)
{
	if ((pre_cmd == 5 && cur_cmd == 7) || (pre_cmd == 7 && cur_cmd == 5) \
		|| (pre_cmd == 6 && cur_cmd == 8) || (pre_cmd == 8 && cur_cmd == 6))
	{
		pre_cmd = 0;
		return (0);
	}
	if ((pre_cmd == 5 && cur_cmd == 6) || (pre_cmd == 6 && cur_cmd == 5) \
		|| (pre_cmd == 7 && cur_cmd == 8) || (pre_cmd == 8 && cur_cmd == 7))
	{
		if (pre_cmd <= 6)
			return (9);
		else
			return (10);
	}
	return (-1);
}

static int	remove_dup_cmd(int *cmds, int cnt, int size)
{
	int	res;
	int	cur_size;

	cur_size = size;
	while (cnt - 1)
	{
		res = optimize_rotate_cmd(cmds[cnt - 2], cmds[cnt - 1]);
		if (res == 0)
		{
			ft_memmove(cmds + cnt - 2, cmds + cnt, (size - cnt) * 4);
			ft_memset(cmds + cur_size - 2, 0, 2 * sizeof(int));
			cnt--;
			cur_size -= 2;
		}
		else if (res == 9 || res == 10)
		{
			cmds[cnt - 2] = res;
			ft_memmove(cmds + cnt - 1, cmds + cnt, (size - cnt) * 4);
			cmds[cur_size--] = 0;
		}
		else
			cnt--;
	}
	return (cur_size);
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
	if (cmd_num == 9)
		ft_putendl_fd("rr", 1);
	if (cmd_num == 10)
		ft_putendl_fd("rrr", 1);
}

static void	exec_rotate_cmds(int *cmds, int *cnt, int cmd_num)
{
	int	size;
	int	i;

	if (*cnt)
	{
		size = remove_dup_cmd(cmds, *cnt, *cnt);
		i = 0;
		while (i < size)
			print_command(cmds[i++]);
	}
	print_command(cmd_num);
	*cnt = 0;
}

void	command_cotroller(t_deque *sa, t_deque *sb, int cmd_num)
{
	static int	cmds[10];
	static int	cnt;

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
	if (cmd_num <= 4 || cnt == 10)
	{
		exec_rotate_cmds(cmds, &cnt, cmd_num);
		return ;
	}
	cmds[cnt++] = cmd_num;
}
