/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_finish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:56:03 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 20:08:21 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

int	is_dead(t_struct *env, t_philo *philo)
{
	unsigned long int	current_time;

	current_time = get_time(env);
	if ((int)(current_time - philo->last_meal) >= env->time_die)
	{
		print_action_terminal("died\n", env, philo, 0);
		return (1);
	}
	return (0);
}

void	kill_childs(t_struct *env)
{
	free(env->philo);
	sem_close(env->sem_fork);
	sem_close(env->sem_print);
	sem_close(env->sem_queue);
	kill(0, SIGKILL);
}

int	check_if_finish(t_struct *env, t_philo *philo)
{
	if (env->nbr_eat == 0)
	{
		free(env->philo);
		sem_close(env->sem_fork);
		sem_close(env->sem_print);
		sem_close(env->sem_queue);
		exit (0);
	}
	else if (is_dead(env, philo))
	{
		kill_childs(env);
	}
	return (0);
}
