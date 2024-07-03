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
	int		c1;
	int		c2;
	int		c3;

	c1 = size / 3;
	c2 = size / 3;
	c3 = size / 3;
	while (size--)
	{
		node = get_node3(sa->header, sa->tail, sb->tail, is_max);
		if (node == sa->header)
		{
			push(sb, sa,"pb\n");
			c1--;
		}
		if (node == sa->tail)
		{
			reverse_rotate(sa, "rra\n");
			push(sb, sa,"pb\n");
			c2--;
		}
		if (node == sb->tail &&c3)
		{
			reverse_rotate(sb, "rrb\n");
			c3--;
		}
	}
}

static void	merge_sa_triangle(t_deque *sa, t_deque *sb, int size, int is_max)
{
	t_list	*node;
	int		c1;
	int		c2;
	int		c3;

	c1 = size / 3;
	c2 = size / 3;
	c3 = size / 3;
	while (size--)
	{
		node = get_node3(sa->tail, sb->header, sb->tail, is_max);
		if ((node == sa->tail && c1) || (!c2 || !c3))
		{
			reverse_rotate(sa, "rra\n");
			c1--;
		}
		if ((node == sb->header && c2) || (!c1 || !c3))
		{
			reverse_rotate(sb, "rrb\n");
			push(sa, sb,"pa\n");
			c2--;
		}
		if ((node == sb->tail && c3) || (!c1 || !c2))
		{
			push(sa, sb,"pa\n");
			c3--;
		}
	}
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size)
{
	static int	is_sa;
	static int	is_max;

	if (size <= 2)
		return ;
	merge_sort(sa, sb, size / 3);
	merge_sort(sa, sb, size / 3);
	merge_sort(sa, sb, size / 3);
	if (!is_sa)
	{
		merge_sb_triangle(sa, sb, size, is_max);
		is_sa = 1;
	}
	else
	{
		merge_sa_triangle(sa, sb, size, is_max);
		is_sa = 0;
	}
	is_max++;
}


void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	int		i;
	int		is_max;

	i = -1;
	while (++i < size / 2)
		push(sb, sa, "pb\n");
	merge_sort(sa, sb, size);

	while (sa->header)
	{
		printf("%d\n", *(int *)(sa->header->content));
		sa->header = sa->header->next;
	}
	printf("\n\n");
	while (sb->header)
	{
		printf("%d\n", *(int *)(sb->header->content));
		sb->header = sb->header->next;
	}
}