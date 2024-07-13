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

static void	merge_3_triangle(t_deque *s1, t_deque *s2, int size, t_is is)
{
	t_list	*node;
	t_size	ts;

	ts = cal_size3(size);
	while (ts.s1 || ts.s2 || ts.s3)
	{
		node = get_node3(s1, s2, ts, is.is_max);
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
		push(s2, s1);
		ts.s3--;
	}
}

static void	merge_12_triangle(t_deque *sa, t_deque *sb, int size, t_is is)
{
	if (is.is_a)
	{
		if (size == 1)
			return ;
		if (is_swap(sa, is.is_max))
			swap(sa);
		return ;
	}
	push(sb, sa);
	if (size == 1)
		return ;
	push(sb, sa);
	if (is_swap(sb, is.is_max))
		swap(sb);
}

static void	merge_triangle(t_deque *sa, t_deque *sb, int size, t_is is)
{
	if (size <= 2)
	{
		merge_12_triangle(sa, sb, size, is);
		return ;
	}
	if (is.is_a)
		merge_3_triangle(sb, sa, size, is);
	else
		merge_3_triangle(sa, sb, size, is);
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size, int depth, t_is is)
{
	t_size		ts;

	ts = cal_size3(size);
	if (size >= 3)
	{
		merge_sort(sa, sb, ts.s1, depth + 1, is_return(is, 1));
		merge_sort(sa, sb, ts.s2, depth + 1, is_return(is, 2));
		merge_sort(sa, sb, ts.s3, depth + 1, is_return(is, 3));
	}
	merge_triangle(sa, sb, size, is);
	if (depth == 0)
		return ;
	while (size-- && !is.is_3)
	{
		if (is.is_a)
			rotate(sa);
		else
			rotate(sb);
	}
}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	t_is	is;

	if (is_sorted(sa))
		return ;
	is.is_max = 1;
	is.is_a = 1;
	is.is_3 = 0;
	merge_sort(sa, sb, size, 0, is);
}
