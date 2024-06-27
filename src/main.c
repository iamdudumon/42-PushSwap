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

static t_list *str_to_stack(char **split)
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
		temp = (t_list *)malloc(sizeof(t_list) * 1);
		if (!temp)
			return (0);
		temp->content = (int *)malloc(sizeof(int) * 1);
		if (!(temp->content))
			return (0);
		*(int *)(temp->content) = ft_atoi(split[i]);
		ft_lstadd_front(&stack, temp);
		i++;
	}
	return (stack);
}

int main(int argc, char *argv[])
{
	char	**split;
	t_list	*stack;

	split = ft_split(argv[1], ' ');
	stack = str_to_stack(split);
}