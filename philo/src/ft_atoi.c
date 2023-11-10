/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:49 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/01 07:29:19 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	check_sign(const char *sign, int *i)
{
	while ((sign[*i] >= 9 && sign[*i] <= 13) || sign[*i] == 32)
	{
		*i += 1;
	}
	if (sign[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	if (sign[*i] == '+')
		*i += 1;
	return (1);
}

int	ft_atoi(char *str)
{
	long int			result;
	int					negative;
	int					i;

	i = 0;
	result = 0;
	negative = check_sign(&str[i], &i);
	if (negative == -1 || str[i] == '\0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result += (str[i] - '0');
		result *= 10;
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	result /= 10;
	if (result > 2147483647)
		return (-1);
	else if (result < -2147483648)
		return (-1);
	return (result);
}
