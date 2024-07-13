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

static void	merge_3_triangle(t_deque *s1, t_deque *s2, int size, int is_max)
{
	t_list	*node;
	t_size	ts;

	ts = cal_size3(size);
	while (ts.s1 || ts.s2 || ts.s3)
	{
		node = get_node3(s1, s2, ts, is_max);
		if (node == s1->tail && ts.s1)
		{
			reverse_rotate(s1);
			push(s2, s1);
			ts.s1--;
			continue ;
		}
		if (node == s2->tail && ts.s2)
		{
			reverse_rotate(s2);
			ts.s2--;
			continue ;
		}
		if (node == s1->header && ts.s3)
		{
			push(s2, s1);
			ts.s3--;
			continue ;
		}
	}
}

static void	merge_12_triangle(t_deque *sa, t_deque *sb, int size, int is_max, int is_a)
{
	if (is_a)
	{
		if (size == 1)
			return ;
		if (is_swap(sa, is_max))
			swap(sa);
		return ;
	}
	push(sb, sa);
	if (size == 1)
		return ;
	push(sb, sa);
	if (is_swap(sb, is_max))
		swap(sb);
}

static void	merge_triangle(t_deque *sa, t_deque *sb, int size, int is_max, int is_a)
{
	if (size <= 2)
		return merge_12_triangle(sa, sb, size, is_max, is_a);
	if (is_a)
		merge_3_triangle(sb, sa, size, is_max);
	else
		merge_3_triangle(sa, sb, size, is_max);
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size, int depth, int is_max, int is_a, int is_3)
{
	t_size		ts;

	ts = cal_size3(size);
	if (size >= 3)
	{
		merge_sort(sa, sb, ts.s1, depth + 1, is_max, is_a == 0, 0);
		merge_sort(sa, sb, ts.s2, depth + 1, is_max, is_a, 0);
		merge_sort(sa, sb, ts.s3, depth + 1, is_max == 0, is_a == 0, 1);
	}
	merge_triangle(sa, sb, size, is_max, is_a);
	if (depth == 0)
		return ;
	while (size-- && !is_3)
		if (is_a)
			rotate(sa);
		else
			rotate(sb);
}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	if (is_sorted(sa))
		return ;
	merge_sort(sa, sb, size, 0, 1, 1, 0);
}