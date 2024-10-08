/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:56:05 by dukim             #+#    #+#             */
/*   Updated: 2024/08/06 17:32:19 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	free_split_str(char **split)
{
	char	**temp;

	temp = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(temp);
}

void	free_stack(t_deque *sa, t_deque *sb)
{
	ft_lstclear(&(sa->header), free);
	if (sb)
		ft_lstclear(&(sb->header), free);
	free(sa);
	if (sb)
		free(sb);
}
