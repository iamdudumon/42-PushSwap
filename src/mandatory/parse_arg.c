/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:43 by dukim             #+#    #+#             */
/*   Updated: 2024/07/16 13:21:44 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

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

static t_list	*create_intnode(char *s, int *set)
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
	stack->len = 0;
	return (stack);
}

static int	str_to_stack(t_deque *stack, char **split, int *set)
{
	int		i;
	int		len;
	t_list	*node;

	len = 0;
	while (split[len])
		len++;
	if (!len)
		return (0);
	i = -1;
	while (++i < len)
	{
		node = create_intnode(split[i], set);
		if (!node)
			return (0);
		ft_lstadd_back(&(stack->header), node);
		stack->tail = node;
	}
	stack->len += len;
	return (1);
}

t_deque	*generate_stack(int argc, char *argv[])
{
	t_deque	*stack;
	char	**split;
	int		*set;
	int		i;

	set = (int *)malloc(sizeof(int) * 1000);
	stack = init_stack();
	if (!set || !stack)
		return (0);
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!str_to_stack(stack, split, set))
		{
			free_stack(stack, 0);
			free(set);
			return (0);
		}
		free_split_str(split);
	}
	free(set);
	return (stack);
}
