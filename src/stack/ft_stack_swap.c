/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:26:37 by dukim             #+#    #+#             */
/*   Updated: 2024/06/24 17:26:39 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_push_swap.h"

void	reverse_rotate(t_list *stack)
{

}

void	reverse_rotate_twin(t_list *as, t_list *bs)
{
    reverse_rotate(as);
    reverse_rotate(bs);
}
