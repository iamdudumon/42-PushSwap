/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:57:57 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 16:57:58 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static int	is_dup_inset(int *set, int integer)
{
	static int	size;
	int			i;

	i = 0;
	while (i < size)
	{
		if (set[i] == integer)
			return (1);
		i++;
	}
	set[i] = integer;
	size++;
	return (0);
}

static t_list	*create_intnode(char *s, int len, int *set)
{
	t_list		*node;
	int			*integer;
	char		error;

	integer = (int *)malloc(sizeof(int) * 1);
	if (!integer)
		return (0);
	error = 0;
	*integer = ft_atoi(s, &error);
	if (error || is_dup_inset(set, *integer))
	{
		free(integer);
		return (0);
	}
	node = ft_lstnew(integer);
	return (node);
}

static t_deque	*init_stack(void)
{
	t_deque	*stack;

	stack = (t_deque *)malloc(sizeof(t_deque) * 1);
	if (!stack)
		return (0);
	stack->header = 0;
	stack->tail = 0;
	return (stack);
}

static t_deque	*str_to_stack(char **split, int len, int *error)
{
	int		i;
	int		*set;
	t_list	*node;
	t_deque	*stack;

	stack = init_stack();
	if (!stack)
		return (0);
	i = -1;
	set = (int *)malloc(sizeof(int) * len);
	if (!set)
		return (0);
	while (++i < len)
	{
		node = create_intnode(split[i], len, set);
		if (!node)
		{
			*error = 1;
			break ;
		}
		ft_lstadd_back(&(stack->header), node);
		// ft_lstadd_back(&(stack->header), &(stack->tail), node);
	}
	stack->tail = node;
	free(set);
	return (stack);
}

int	main(int argc, char *argv[])
{
	char	**split;
	int		len;
	int		error;
	t_deque	*sa;
	t_deque	*sb;

	split = ft_split(argv[1], ' ');
	len = 0;
	error = 0;
	while (split[len])
		len++;
	sa = str_to_stack(split, len, &error);
	sb = str_to_stack(0, 0, &error);
	free_split_str(split);
	if (error)
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(sa, sb);
		return (0);
	}
	push_swap(sa, sb, len);
	free_stack(sa, sb);
}

// rotate(stack);
// //reverse_rotate(stack);
// while (stack)
// {
// 	printf("%d\n", *(int *)(stack->content));
// 	stack = stack->next;
// }
