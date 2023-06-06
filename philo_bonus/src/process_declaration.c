/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_declaration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 07:33:36 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 19:27:33 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

void	create_philo(t_struct *env, int i)
{
	env->philo[i].pid = fork();
	if (env->philo[i].pid < 0)
		quit_function(env, 1);
	else if (env->philo[i].pid == 0)
		philo_routine(env, &env->philo[i]);
}

void	semaphore_init(t_struct *env)
{
	sem_unlink("sem_print");
	sem_unlink("sem_fork");
	sem_unlink("sem_queue");
	env->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (env->sem_print == SEM_FAILED)
		quit_function(env, 1);
	env->sem_fork = \
		sem_open("sem_fork", O_CREAT | O_EXCL, 0644, env->nbr_philo);
	if (env->sem_fork == SEM_FAILED)
		quit_function(env, 1);
	env->sem_queue = sem_open("sem_queue", O_CREAT | O_EXCL, 0644, 1);
	if (env->sem_queue == SEM_FAILED)
		quit_function(env, 1);
}

void	semaphore_destroy(t_struct *env)
{
	sem_close(env->sem_print);
	sem_close(env->sem_fork);
	sem_close(env->sem_queue);
}

int	process_declaration(t_struct *env)
{
	int		i;

	i = 0;
	semaphore_init(env);
	while (i < env->nbr_philo)
	{
		create_philo(env, i);
		i++;
	}
	i = 0;
	while (i < env->nbr_philo)
	{
		waitpid(env->philo[i].pid, 0, 0);
		i++;
	}
	semaphore_destroy(env);
	return (0);
}
