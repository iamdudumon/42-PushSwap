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

static void	merge_sb_triangle(t_deque *sa, t_deque *sb, int size, int is_max)
{
	t_list	*node;
	t_size	ts;

	ts = cal_size3(size);
	while (ts.s1 || ts.s2 || ts.s3)
	{
		node = get_node3(sa->tail, sb->tail, sa->header, is_max, ts);
		if (node == sa->tail && ts.s1)
		{
			reverse_rotate(sa, "rra\n");
			push(sb, sa, "pb\n");
			ts.s1--;
			continue ;
		}
		if (node == sb->tail && ts.s2)
		{
			reverse_rotate(sb, "rrb\n");
			ts.s2--;
			continue ;
		}
		if (node == sa->header && ts.s3)
		{
			push(sb, sa, "pb\n");
			ts.s3--;
			continue ;
		}
	}
}

static void	merge_sa_triangle(t_deque *sa, t_deque *sb, int size, int is_max)
{
	t_list	*node;
	t_size	ts;

	ts = cal_size3(size);
	while (ts.s1 || ts.s2 || ts.s3)
	{
		node = get_node3(sb->tail, sa->tail, sb->header, is_max, ts);
		if (node == sb->tail && ts.s1)
		{
			if (size >= 3)
			{
				reverse_rotate(sb, "rrb\n");
				push(sa, sb, "pa\n");
			}
			ts.s1--;
			continue ;
		}
		if (node == sa->tail && ts.s2)
		{
			reverse_rotate(sa, "rra\n");
			ts.s2--;
			continue ;
		}
		if (node == sb->header && ts.s3)
		{
			push(sa, sb, "pa\n");
			ts.s3--;
			continue ;
		}
	}
}

static void	merge_small_triangle(t_deque *sa, t_deque *sb, int size, int is_max, int is_a)
{
	t_size	ts;

	ts = cal_size3(size);
	if (is_a)
	{
		if (size == 1)
			return ;
		if (is_swap(sa, is_max))
			swap(sa, "sa\n");
	}
	else
	{
		push(sb, sa, "pb\n");
		if (size == 1)
			return ;
		push(sb, sa, "pb\n");
		if (is_swap(sb, is_max))
			swap(sb, "sb\n");
	}
}

static void	merge_triangle(t_deque *sa, t_deque *sb, int size, int is_max, int is_a)
{
	if (size <= 2)
		return merge_small_triangle(sa, sb, size, is_max, is_a);
	if (is_a)
		merge_sa_triangle(sa, sb, size, is_max);
	else
		merge_sb_triangle(sa, sb, size, is_max);
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size, int depth, int is_max)
{
	static int	*cnts;
	t_size		ts;
	int			cnt;
	int			is_a;

	if (!cnts)
	{
		cnts = (int *)malloc(sizeof(int) * (10 + 1));
		ft_memset(cnts, 0, sizeof(int) * (10 + 1));
	}
	ts = cal_size3(size);
	if (size >= 3)
	{
		merge_sort(sa, sb, ts.s1, depth + 1, is_max);
		merge_sort(sa, sb, ts.s2, depth + 1, is_max);
		merge_sort(sa, sb, ts.s3, depth + 1, is_max == 0);
	}
	cnt = cnts[depth]++;
	is_a = (cnt + depth + 1) % 2;
	merge_triangle(sa, sb, size, is_max, is_a);
	if (depth == 0)
		return free(cnts);
	if (size == 2)
		cnts[depth + 1] += 3;
	while (size-- && cnt % 3 != 2)
		if (is_a)
			rotate(sa, "ra\n");
		else
			rotate(sb, "rb\n");

}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	merge_sort(sa, sb, size, 0, 1);
}