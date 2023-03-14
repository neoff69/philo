/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_declaration.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:09:56 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/06 14:37:50 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*execution(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	if (philo->nbr_philo == 1)
		philo_routine(philo, NULL);
	else if (philo->who == 1)
		philo_routine(philo, (philo + (philo->nbr_philo - 1)));
	else
		philo_routine(philo, (philo -1));
	return (NULL);
}

int	create_thread(t_philo *philo, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < philo->nbr_philo)
	{
		if (pthread_create(&thread[i], NULL, &execution, &philo[i]))
		{
			printf("Error at creating thread\n");
			free(thread);
			return (1);
		}
		usleep(200);
		i ++;
	}
	return (0);
}

int	thread_declaration(t_philo *philo)
{
	pthread_t				*thread;

	thread = malloc(sizeof(pthread_t) * (philo[0].nbr_philo));
	if (thread == NULL)
		return (1);
	if (mutex_init(philo) || create_thread(philo, thread))
	{
		free(thread);
		return (1);
	}
	while (1)
	{
		if (check_if_finish(philo))
			break ;
		usleep(50);
	}
	if (join_thread(philo, thread) == 1)
		return (1);
	mutex_destroy(philo);
	return (0);
}
