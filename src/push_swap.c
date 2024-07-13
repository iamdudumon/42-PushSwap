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

static int	is_sorted(t_deque *sa)
{
	t_list	*ptr;

	ptr = sa->header;
	while (ptr->next)
	{
		if (*(int *)(ptr->content) > *(int *)(ptr->next->content))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

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

static void	merge_sort(t_deque *sa, t_deque *sb, int size, int *cnts, int depth, int is_max)
{
	t_size	ts;
	int		cnt;

	ts = cal_size3(size);
	cnt = cnts[depth];
	if (size >= 3)
	{
		merge_sort(sa, sb, ts.s1, cnts, depth + 1, is_max);
		merge_sort(sa, sb, ts.s2, cnts, depth + 1, is_max);
		merge_sort(sa, sb, ts.s3, cnts, depth + 1, is_max == 0);
	}
	if (size <= 2)
		merge_small_triangle(sa, sb, size, is_max, (depth + cnt + 1) % 2);
	else
	{
		if ((depth + cnt + 1) % 2)
			merge_sa_triangle(sa, sb, size, is_max);
		else
			merge_sb_triangle(sa, sb, size, is_max);
	}
	if (depth == 0)
		return ;
	cnts[depth]++;
	if (size == 2)
		cnts[depth + 1] += 3;
	while (size-- && cnt % 3 != 2)
	{
		if ((depth + cnt + 1) % 2)
			rotate(sa, "ra\n");
		else
			rotate(sb, "rb\n");
	}
}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	int		i;
	int		depth;
	int		*cnts;

	// i = -1;
	// while (++i < size / 2)
	// 	push(sb, sa, "pb\n");
	depth = get_depth(size);
	cnts = (int *)malloc(sizeof(int) * (depth + 1));
	// i = -1;
	// while (++i < depth)
	// 	cnts[i] = 0;
	ft_memset(cnts, 0, sizeof(int) * (depth + 1));
	merge_sort(sa, sb, size, cnts, 0, 1);
	free(cnts);
}