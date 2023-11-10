/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:18:36 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/22 14:11:25 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	check_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->mutex);
	stop = philo->stop;
	pthread_mutex_unlock(&philo->mutex);
	return (stop);
}

void	lock_and_mutex(t_philo *mid_philo, t_philo *left_philo, \
						t_philo *philo_print)
{
	pthread_mutex_lock(&left_philo->mutex_fork);
	print_action_terminal("has taken a fork\n", philo_print);
	pthread_mutex_lock(&mid_philo->mutex_fork);
	print_action_terminal("has taken a fork\n", philo_print);
}

void	mutex_lock(t_philo *philo, t_philo *left_philo)
{
	if (philo->who == 1)
		lock_and_mutex(left_philo, philo, philo);
	else
		lock_and_mutex(philo, left_philo, philo);
	philo->mid_lock = 1;
	philo->left_lock = 1;
}

void	mutex_unlock(t_philo *philo, t_philo *left_philo)
{
	if (philo->mid_lock == 1)
	{
		pthread_mutex_unlock(&philo->mutex_fork);
		philo->mid_lock = 0;
	}
	if (philo->left_lock == 1)
	{
		pthread_mutex_unlock(&left_philo->mutex_fork);
		philo->left_lock = 0;
	}
}

int	quit_thread(t_philo *philo, t_philo *left_philo)
{
	mutex_unlock(philo, left_philo);
	return (1);
}
