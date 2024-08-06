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

int	ft_atoi(const char *nptr, char *error)
{
	long	sum;
	int		minus_cnt;

	sum = 0;
	minus_cnt = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus_cnt++;
		nptr++;
	}
	while (*nptr != '\0')
	{
		sum = sum * 10 + (*nptr - '0');
		if (!ft_isdigit(*nptr) || (*nptr == ' ' && sum) || \
					sum > 2147483647 || sum < -2147483648)
		{
			*error = 1;
			return (0);
		}
		nptr++;
	}
	if (minus_cnt)
		sum = -sum;
	return (sum);
}
