/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:52:06 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/17 17:47:55 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	check_if_stop(t_philo *philo)
{	
	pthread_mutex_lock(&philo->mutex);
	if (philo->stop == 1)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

static int	eating_exec(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->stop == 1)
	{
		pthread_mutex_unlock(&philo->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex);
	philo->last_meal = get_time(philo);
	print_action_terminal("is eating\n", philo, 0);
	usleep(philo->time_eat * 1000);
	if (philo->nbr_eat > 0)
	{
		pthread_mutex_lock(&philo->mutex_time);
		philo->nbr_eat--;
		pthread_mutex_unlock(&philo->mutex_time);
	}
	return (0);
}

static void	sleeping_exec(t_philo *philo)
{
	print_action_terminal("is sleeping\n", philo, 0);
	usleep(philo->time_sleep * 1000);
}

int	eating_routine(t_philo *philo, t_philo *left_philo)
{
	int	stop;

	stop = 0;
	if (check_if_stop(philo) == 1)
		return (1);
	eating_exec(philo);
	pthread_mutex_lock(&philo->mutex);
	if (philo->stop == 1)
		stop = 1;
	mutex_unlock(philo, left_philo);
	pthread_mutex_unlock(&philo->mutex);
	if (stop == 1)
		return (stop);
	sleeping_exec(philo);
	return (0);
}
