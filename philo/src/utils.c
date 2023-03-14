/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:38:13 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/02 12:35:44 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

unsigned long int	get_time(t_philo *philo)
{
	unsigned long int	time;

	gettimeofday(&philo->tv, NULL);
	time = 1000000 * philo->tv.tv_sec + philo->tv.tv_usec;
	time = (time - philo->time_start) * 0.001;
	return (time);
}

int	print_action_terminal(char *str, t_philo *philo)
{
	pthread_mutex_lock(&(philo)->mutex_printf);
	printf("%lu %d %s", get_time(philo), philo->who, str);
	pthread_mutex_unlock(&(philo)->mutex_printf);
	return (0);
}
