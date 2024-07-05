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

void	print_stack(t_list *sa, t_list *sb)
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
	int		ori_size;

	ori_size = size;
	c1 = size / 3;
	c2 = size / 3;
	c3 = size / 3;
	while (size--)
	{
		node = get_node3(sa->header, sa->tail, sb->tail, is_max, c1, c2, c3);
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
		if (node == sb->tail)
		{
			reverse_rotate(sb, "rrb\n");
			c3--;
		}
	}
	if (is_max % 3 == 2)
		return ;
	while (ori_size--)
		rotate(sb, "rb\n");
}

static void	merge_sa_triangle(t_deque *sa, t_deque *sb, int size, int is_max)
{
	t_list	*node;
	int		c1;
	int		c2;
	int		c3;
	int		ori_size;

	ori_size = size;
	c1 = size / 3;
	c2 = size / 3;
	c3 = size / 3;
	while (size--)
	{
		node = get_node3(sa->tail, sb->header, sb->tail, is_max, c1, c2, c3);
		if (node == sa->tail)
		{
			reverse_rotate(sa, "rra\n");
			c1--;
		}
		if (node == sb->header)
		{
			push(sa, sb,"pa\n");
			c2--;
		}
		if (node == sb->tail)
		{
			reverse_rotate(sb, "rrb\n");
			push(sa, sb,"pa\n");
			c3--;
		}
	}
	if (is_max % 3 == 2)
		return ;
	while (ori_size--)
		rotate(sa, "ra\n");
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size, int *cnts)
{
	int	ori_size;
	int	cnt;
	int	depth;

	if (size <= 2)
		return ;
	merge_sort(sa, sb, size / 3, cnts);
	merge_sort(sa, sb, size / 3, cnts);
	merge_sort(sa, sb, size / 3, cnts);
	ori_size = size / 3;
	depth = get_depth(size);
	cnt = cnts[depth - 1];
	if (cnt == depth % 2)
		ori_size = 0;
	while (ori_size)
	{
		rotate_twin(sa, sb);
		ori_size--;
	} 
	if ((cnt + depth - 1) % 2 == 0)
		merge_sb_triangle(sa, sb, size, cnt);
	else
		merge_sa_triangle(sa, sb, size, cnt);
	cnts[depth - 1]++;
}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	int	i;
	int	*cnts;
	int	depth;

	i = -1;
	while (++i < size / 2)
		push(sb, sa, "pb\n");
	depth = get_depth(size);
	cnts = (int *)malloc(sizeof(int) * depth);
	i = -1;
	while (++i < depth)
		cnts[i] = (i + depth) % 2;
	merge_sort(sa, sb, size, cnts);
}