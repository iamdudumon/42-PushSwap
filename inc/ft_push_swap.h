/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:52:58 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 16:52:59 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_deque
{
	t_list	*header;
	t_list	*tail;
}			t_deque;

typedef struct s_layer
{
	char	is_a;
	int		cnt;
}			t_layer;

void	swap(t_deque *stack, char *cmd);
void	swap_twin(t_deque *as, t_deque *bs);
void	push(t_deque *to, t_deque *from, char *cmd);
void	rotate(t_deque *stack, char *cmd);
void	rotate_twin(t_deque *as, t_deque *bs);
void	reverse_rotate(t_deque *stack, char *cmd);
void	reverse_rotate_twin(t_deque *as, t_deque *bs);

void	free_split_str(char **split);
void	free_stack(t_deque *sa, t_deque *sb);

t_list	*get_node3(t_list *node1, t_list *node2, t_list *node3, int is_max, int c1, int c2, int c3);
int		get_depth(int size);
int		is_swap(t_deque *stack, int is_max);

void	push_swap(t_deque *sa, t_deque *sb, int size);

#endif