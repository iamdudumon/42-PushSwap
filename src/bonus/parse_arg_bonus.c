/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:43 by dukim             #+#    #+#             */
/*   Updated: 2024/08/06 17:32:24 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap_bonus.h"

static int	is_dup_instack(t_deque *stack, int integer)
{
	t_list	*ptr;
	
	ptr = stack->header;
	while (ptr)
	{
		if (*(int *)ptr->content == integer)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static t_list	*create_intnode(t_deque *stack, char *s)
{
	t_list		*node;
	int			*integer;
	char		error;

	integer = (int *)malloc(sizeof(int) * 1);
	if (!integer)
		return (0);
	error = 0;
	*integer = ft_atoi(s, &error);
	if (error || is_dup_instack(stack, *integer))
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

static int	str_to_stack(t_deque *stack, char **split)
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
		node = create_intnode(stack, split[i]);
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
	int		i;

	stack = init_stack();
	if (!stack)
		return (0);
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!str_to_stack(stack, split))
		{
			free_stack(stack, 0);
			free_split_str(split);
			return (0);
		}
		free_split_str(split);
	}
	return (stack);
}

