/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:46:45 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/17 17:56:25 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	is_dead(t_philo philo)
{
	unsigned long int	current_time;

	current_time = get_time(&philo);
	if ((int)(current_time - philo.last_meal) >= philo.time_die)
	{
		print_action_terminal("died\n", &philo, 1);
		return (1);
	}
	return (0);
}

int	is_nbr_food_zero(t_philo philo)
{
	pthread_mutex_lock(&philo.mutex_time);
	if (philo.nbr_eat == 0)
	{
		pthread_mutex_unlock(&philo.mutex_time);
		return (1);
	}
	pthread_mutex_unlock(&philo.mutex_time);
	return (0);
}

int	set_stop(t_philo *philo, int i, int unlock)
{
	int	min;
	int	max;

	min = 0;
	max = philo[0].nbr_philo - 1;
	if (unlock)
		pthread_mutex_unlock(&philo[i].mutex);
	while (min <= max)
	{
		pthread_mutex_lock(&philo[min].mutex);
		philo[min].stop = 1;
		pthread_mutex_unlock(&philo[min].mutex);
		pthread_mutex_lock(&philo[max].mutex);
		philo[max].stop = 1;
		pthread_mutex_unlock(&philo[max].mutex);
		min++;
		max--;
	}
	return (1);
}

int	check_if_finish(t_philo *philo)
{
	int						i;
	int						eat_enough;

	i = 0;
	eat_enough = 0;
	while (i < philo[0].nbr_philo)
	{
		eat_enough += is_nbr_food_zero(philo[i]);
		if (eat_enough == philo[0].nbr_philo)
			return (set_stop(philo, i, 0));
		pthread_mutex_lock(&philo[i].mutex);
		if (is_dead(philo[i]) == 1)
			return (set_stop(philo, i, 1));
		else if (philo[i].stop)
			return (set_stop(philo, i, 1));
		pthread_mutex_unlock(&philo[i].mutex);
		i++;
	}
	return (0);
}
