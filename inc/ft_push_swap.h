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

# include <stdio.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	struct s_list   *prev;
// }					t_list;

void	swap(t_list *stack);
void	swap_twin(t_list *as, t_list *bs);
void	push(t_list **to, t_list **from);
void	rotate(t_list *stack);
void	rotate_twin(t_list *as, t_list *bs);
void	reverse_rotate(t_list *stack);
void	reverse_rotate_twin(t_list *as, t_list *bs);

int 	exec_commands(t_list *sa, t_list *sb);
void	free_split_str(char **split);
void	free_stack(t_list *sa, t_list *sb);

int     is_sorted(t_list *sa);
void	push_swap(t_list *sa, t_list *sb, int size);

#endif