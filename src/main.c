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

#include <stdio.h>

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

static t_list	*create_intnode(const char *s, int len)
{
	static int	*set;
	t_list		*node;
	int			*integer;
	char		error;

	if (!set)
		set = (int *)malloc(sizeof(int) * len);
	integer = (int *)malloc(sizeof(int) * 1);
	if (!set || !integer)
		return (0);
	error = 0;
	*integer = ft_atoi(s, &error);
	if (is_dup_inset(set, *integer))
		return (0);
	if (error)
		return (0);
	node = ft_lstnew(integer);
	if (!node)
		return (0);
	return (node);
}

static t_list	*str_to_stack(char **split)
{
	int		i;
	int		len;
	t_list	*temp;
	t_list	*stack;

	len = 0;
	while (split[len])
		len++;
	stack = 0;
	i = 0;
	while (i < len)
	{
		temp = create_intnode(split[i], len);
		if (!temp)
			return (0);
		ft_lstadd_front(&stack, temp);
		i++;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	char	**split;
	t_list	*stack;

	split = ft_split(argv[1], ' ');
	stack = str_to_stack(split);
	if (!stack)
	{
		printf("error\n");
		return (0);
	}
}

// while (stack)
// {
// 	printf("%d\n", *(int *)(stack->content));
// 	stack = stack->next;
// }
