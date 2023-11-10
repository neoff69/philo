/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:46:45 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/14 10:55:13 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	is_dead(long last_meal, long time_die, t_data *data, int who)
{
	unsigned long int	current_time;

	current_time = get_time(data->time_start, data->tv);
	if ((int)(current_time - last_meal) >= time_die)
	{
		print_action_main("died\n", data, who);
		return (1);
	}
	return (0);
}

int	is_nbr_food_zero(int nbr_eat)
{
	if (nbr_eat == 0)
	{
		return (1);
	}
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

int	check_if_finish(t_philo *philo, t_data *data)
{
	int						i;
	int						eat_enough;

	i = 0;
	eat_enough = 0;
	while (i < philo[0].nbr_philo)
	{
		pthread_mutex_lock(&philo[i].mutex);
		pthread_mutex_lock(&philo[i].mutex_time);
		eat_enough += is_nbr_food_zero(philo[i].nbr_eat);
		pthread_mutex_unlock(&philo[i].mutex_time);
		if (eat_enough == philo[0].nbr_philo)
		{
			return (set_stop(philo, i, 1));
		}
		if (is_dead(philo[i].last_meal, philo[i].time_die, \
					data, philo[i].who) == 1)
			return (set_stop(philo, i, 1));
		else if (philo[i].stop)
			return (set_stop(philo, i, 1));
		pthread_mutex_unlock(&philo[i].mutex);
		i++;
	}
	return (0);
}
