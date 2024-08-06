/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:11:29 by dukim             #+#    #+#             */
/*   Updated: 2024/08/06 18:11:30 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_deque
{
	t_list			*header;
	t_list			*tail;
	unsigned int	len;
	char			name;
}					t_deque;

void	swap(t_deque *stack);
void	twin_swap(t_deque *sa, t_deque *sb);
void	push(t_deque *to, t_deque *from);
void	rotate(t_deque *stack);
void	twin_rotate(t_deque *sa, t_deque *sb);
void	reverse_rotate(t_deque *stack);
void	twin_reverse_rotate(t_deque *sa, t_deque *sb);

t_deque	*generate_stack(int argc, char *argv[]);
void	free_split_str(char **split);
void	free_stack(t_deque *sa, t_deque *sb);

void	check_sorted(t_deque *sa, t_deque *sb);

#endif
