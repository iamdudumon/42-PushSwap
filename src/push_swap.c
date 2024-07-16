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

static void	merge_big_triangle(t_deque *s1, t_deque *s2, int size, t_is is)
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

static void	merge_small_triangle(t_deque *sa, t_deque *sb, int size, t_is is)
{
	if (is.is_a)
	{
		if (size == 1)
			return ;
		if (is_swap(sa, is.is_max))
			swap(sa);
		if (size == 3)
			sort_3_triangle(sa, 3, is.is_max);
		return ;
	}
	push(sb, sa);
	if (size == 1)
		return ;
	push(sb, sa);
	if (is_swap(sb, is.is_max))
		swap(sb);
	if (size == 3)
	{
		push(sb, sa);
		if (is_swap(sb, is.is_max))
			swap(sb);
		sort_3_triangle(sb, 3, is.is_max);
	}
}

static void	merge_triangle(t_deque *sa, t_deque *sb, int size, t_is is)
{
	if (size <= 3)
	{
		merge_small_triangle(sa, sb, size, is);
		return ;
	}
	if (is.is_a)
		merge_big_triangle(sb, sa, size, is);
	else
		merge_big_triangle(sa, sb, size, is);
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size, t_is is)
{
	t_size		ts;

	if (earlyreturn_sorted_stack(sa, sb, size, is))
		return ;
	ts = cal_size3(size);
	if (size >= 4)
	{
		merge_sort(sa, sb, ts.s1, is_return(is, 1));
		merge_sort(sa, sb, ts.s2, is_return(is, 2));
		merge_sort(sa, sb, ts.s3, is_return(is, 3));
	}
	merge_triangle(sa, sb, size, is);
	if (is.is_3 || (!(sb->header) && is_sorted(sa, sa->len, 1)))
		return ;
	if (is.is_a)
		drop_triangle_bottom(sa, size);
	else
		drop_triangle_bottom(sb, size);
}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	t_is	is;

	if (is_sorted(sa, sa->len, 1))
		return ;
	is.is_max = 1;
	is.is_a = 1;
	is.is_3 = 0;
	merge_sort(sa, sb, size, is);
}
