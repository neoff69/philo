/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:53:45 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 20:02:35 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

void	thinking_routine(t_struct *env, t_philo *philo)
{
	print_action_terminal("is thinking\n", env, philo, 1);
}

void	taking_fork_routine(t_struct *env, t_philo *philo)
{
	check_if_finish(env, philo);
	sem_wait(env->sem_queue);
	sem_wait(env->sem_fork);
	print_action_terminal("has taken a fork\n", env, philo, 1);
	sem_wait(env->sem_fork);
	print_action_terminal("has taken a fork\n", env, philo, 1);
	sem_post(env->sem_queue);
	check_if_finish(env, philo);
}

void	eating_routine(t_struct *env, t_philo *philo)
{
	check_if_finish(env, philo);
	philo->last_meal = get_time(env);
	print_action_terminal("is eating\n", env, philo, 1);
	env->nbr_eat -= 1;
	usleep(env->time_eat * 1000);
	sem_post(env->sem_fork);
	sem_post(env->sem_fork);
	check_if_finish(env, philo);
}

void	sleeping_routine(t_struct *env, t_philo *philo)
{
	check_if_finish(env, philo);
	print_action_terminal("is sleeping\n", env, philo, 1);
	usleep(env->time_sleep * 1000);
}

void	philo_routine(t_struct *env, t_philo *philo)
{
	if (env->nbr_philo == 1)
	{
		thinking_routine(env, philo);
		usleep(env->time_die * 1000);
		quit_function(env, 0);
	}
	while (1)
	{
		thinking_routine(env, philo);
		taking_fork_routine(env, philo);
		eating_routine(env, philo);
		sleeping_routine(env, philo);
	}
	quit_function(env, -1);
}
