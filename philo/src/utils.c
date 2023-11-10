/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:38:13 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/14 11:54:58 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

unsigned long int	get_time(long time_start, struct timeval tv)
{
	unsigned long int	time;

	gettimeofday(&tv, NULL);
	time = 1000000 * tv.tv_sec + tv.tv_usec;
	time = (time - time_start) * 0.001;
	return (time);
}

void	print_action_terminal(char *str, t_philo *philo)
{
	unsigned long	time;

	time = get_time(philo->time_start, philo->tv);
	if (check_stop(philo) == 1)
		return ;
	pthread_mutex_lock(philo->mutex_printf);
	printf("%lu %d %s", time, \
			philo->who, str);
	pthread_mutex_unlock(philo->mutex_printf);
}

void	print_action_main(char *str, t_data *data, int who)
{
	unsigned long	time;

	time = get_time(data->time_start, data->tv);
	pthread_mutex_lock(&data->mutex_printf);
	printf("%lu %d %s", time, who, str);
	pthread_mutex_unlock(&data->mutex_printf);
}
