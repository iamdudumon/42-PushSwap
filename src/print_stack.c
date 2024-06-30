/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:04:12 by dukim             #+#    #+#             */
/*   Updated: 2024/06/30 18:04:32 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"
# include <stdio.h>

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
