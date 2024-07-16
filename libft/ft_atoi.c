/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:13:00 by dukim             #+#    #+#             */
/*   Updated: 2024/02/29 11:26:51 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign_ch(char ch)
{
	if (ch == '+' || ch == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, char *error)
{
	long	sum;
	int		minus_cnt;

	sum = 0;
	minus_cnt = 0;
	if (is_sign_ch(*nptr))
	{
		minus_cnt++;
		nptr++;
	}
	while (*nptr != '\0')
	{
		if (!ft_isdigit(*nptr))
			*error = 1;
		sum = sum * 10 + (*nptr - '0');
		if (sum > 2147483647 || sum < -2147483648)
			*error = 1;
		nptr++;
	}
	if (minus_cnt)
		sum = -sum;
	return (sum);
}
