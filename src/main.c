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

int	main(int argc, char *argv[])
{
	int		len;
	t_deque	*sa;
	t_deque	*sb;

	if (argc <= 1)
		return (0);
	sa = generate_stack(argc, argv);
	sb = generate_stack(0, 0);
	if (!sa || !sb)
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(sa, sb);
		return (0);
	}
	sa->name = 'A';
	sb->name = 'B';
	push_swap(sa, sb, sa->len);
	free_stack(sa, sb);
}
