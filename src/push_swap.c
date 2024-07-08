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

	c1 = size / 3;
	c2 = size / 3;
	c3 = size / 3;
	while (c1 || c2 || c3)
	{
		node = get_node3(sa->header, sa->tail, sb->tail, is_max, c1, c2, c3);
		if (node == sa->header && c1)
		{
			push(sb, sa, "pb\n");
			c1--;
		}
		if (node == sa->tail && c2)
		{
			reverse_rotate(sa, "rra\n");
			push(sb, sa, "pb\n");
			c2--;
		}
		if (node == sb->tail && c3)
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
	while (c1 || c2 || c3)
	{
		node = get_node3(sa->tail, sb->header, sb->tail, is_max, c1, c2, c3);
		if (node == sa->tail && c1)
		{
			reverse_rotate(sa, "rra\n");
			c1--;
		}
		if (node == sb->header && c2)
		{
			push(sa, sb, "pa\n");
			c2--;
		}
		if (node == sb->tail && c3)
		{
			reverse_rotate(sb, "rrb\n");
			push(sa, sb, "pa\n");
			c3--;
		}
	}
}

static void	merge_sort(t_deque *sa, t_deque *sb, int size, t_layer *layers, int is_max)
{
	int		depth;
	char	is_a;
	int		cnt;

	if (size <= 2)
		return ;
	merge_sort(sa, sb, size / 3, layers, is_max);
	merge_sort(sa, sb, size / 3, layers, is_max);
	merge_sort(sa, sb, size / 3, layers, is_max == 0);
	depth = get_depth(size);
	is_a = layers[depth - 1].is_a;
	cnt = layers[depth - 1].cnt++;
	if ((is_a + cnt) % 2)
		merge_sa_triangle(sa, sb, size, is_max);
	else
		merge_sb_triangle(sa, sb, size, is_max);
	if (cnt % 3 == 2)
		return ;
	while (size--)
	{
		if ((is_a + cnt) % 2)
			rotate(sa, "ra\n");
		else
			rotate(sb, "rb\n");
	}
	rotate_twin(sa, sb);
}

void	push_swap(t_deque *sa, t_deque *sb, int size)
{
	int		i;
	int		depth;
	t_layer	*layers;

	i = -1;
	while (++i < size / 2)
		push(sb, sa, "pb\n");
	depth = get_depth(size);
	layers = (t_layer *)malloc(sizeof(t_layer) * depth);
	i = -1;
	while (++i < depth)
	{
		layers[i].is_a = (i + depth) % 2;
		layers[i].cnt = 0;
	}
	merge_sort(sa, sb, size, layers, 1);
	free(layers);
}