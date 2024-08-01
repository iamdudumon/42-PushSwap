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

#include "../../inc/ft_push_swap.h"

void	sort_smail3(t_deque *sa)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)sa->header->content;
	second = *(int *)sa->header->next->content;
	third = *(int *)sa->header->next->next->content;
	if (first < second && second > third && first > third)
		command_cotroller(sa, 0, 7);
	else if (first > second && second < third && first > third)
		command_cotroller(sa, 0, 5);
	else if (first > second && second > third)
	{
		command_cotroller(sa, 0, 5);
		command_cotroller(sa, 0, 1);
	}
	else if (first < second && second > third && first < third)
	{
		command_cotroller(sa, 0, 7);
		command_cotroller(sa, 0, 1);
	}
	else if (first > second && second < third && first < third)
		command_cotroller(sa, 0, 1);
	command_cotroller(sa, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_deque	*sa;
	t_deque	*sb;

	if (argc <= 1)
		return (0);
	sa = generate_stack(argc, argv);
	sb = generate_stack(0, 0);
	if (!sa || !sa->len || !sb)
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(sa, sb);
		return (0);
	}
	sa->name = 'A';
	sb->name = 'B';
	if (sa->len == 3)
		sort_smail3(sa);
	else
		push_swap(sa, sb, sa->len);
	free_stack(sa, sb);
}
