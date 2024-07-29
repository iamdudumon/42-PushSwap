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
	t_list			*header;
	t_list			*tail;
	unsigned int	len;
	char			name;
}					t_deque;

typedef struct s_is
{
	char		is_max;
	char		is_a;
	char		is_3;
}				t_is;

typedef struct s_size
{
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	s3;
}					t_size;

void	swap(t_deque *stack);
void	push(t_deque *to, t_deque *from);
void	rotate(t_deque *stack);
void	reverse_rotate(t_deque *stack);

void	free_split_str(char **split);
void	free_stack(t_deque *sa, t_deque *sb);

t_list	*get_node3(t_deque *s1, t_deque *s2, t_size ts, int is_max);
int		is_sorted(t_deque *stack, unsigned int size, char is_max);
int		is_swap(t_deque *stack, int is_max);
t_size	cal_size3(int size);
t_is	is_return(t_is is, int n);

void	exec_s1_tail(t_deque *s1, t_deque *s2);
void	exec_s2_tail(t_deque *s1, t_deque *s2);
void	exec_s1_head(t_deque *s1, t_deque *s2);

void	drop_triangle_bottom(t_deque *stack, unsigned int size);
void	sort_3_triangle(t_deque *stack, unsigned int size, char is_max);
int		earlyreturn_sorted_stack(t_deque *sa, t_deque *sb, \
									unsigned int size, t_is is);
void	command_cotroller(t_deque *sa, t_deque *sb, int cmd_num);

t_deque	*generate_stack(int argc, char *argv[]);

void	push_swap(t_deque *sa, t_deque *sb, int size);

#endif