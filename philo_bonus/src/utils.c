/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:15:34 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/06 17:50:33 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

void	quit_function(t_struct *env, int error)
{
	free(env->philo);
	if (env->sem_fork != NULL || env->sem_fork != SEM_FAILED)
		sem_close(env->sem_fork);
	if (env->sem_print != NULL || env->sem_print != SEM_FAILED)
		sem_close(env->sem_print);
	if (error == 0)
		exit (0);
	if (error == 1)
	{
		printf("Error :%s", strerror(errno));
		exit (1);
	}
}

unsigned long int	get_time(t_struct *env)
{
	unsigned long int	time;

	gettimeofday(&env->tv, NULL);
	time = 1000000 * env->tv.tv_sec + env->tv.tv_usec;
	time = (time - env->time_start) * 0.001;
	return (time);
}

int	print_action_terminal(char *str, t_struct *env, t_philo *philo, int alive)
{
	sem_wait(env->sem_print);
	printf("%lu %d %s", get_time(env), philo->who, str);
	if (alive)
		sem_post(env->sem_print);
	return (0);
}
