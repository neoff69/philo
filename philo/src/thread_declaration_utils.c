/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_declaration_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:16:59 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/06 14:42:53 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	mutex_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo[0].mutex_printf);
	while (i < philo[0].nbr_philo)
	{
		if (pthread_mutex_destroy(&philo[i].mutex))
			return (1);
		if (pthread_mutex_destroy(&philo[i].mutex_fork))
			return (1);
		if (pthread_mutex_destroy(&philo[i].mutex_time))
			return (1);
		i++;
	}
	return (0);
}

int	mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo[0].mutex_printf, NULL);
	while (i < philo->nbr_philo)
	{
		if (i > 0)
			philo[i].mutex_printf = philo[0].mutex_printf;
		if (pthread_mutex_init(&philo[i].mutex, NULL))
			return (1);
		if (pthread_mutex_init(&philo[i].mutex_fork, NULL))
			return (1);
		if (pthread_mutex_init(&philo[i].mutex_time, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	join_thread(t_philo *philo, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < philo[0].nbr_philo)
	{
		if (thread[i] && pthread_join(thread[i], NULL) != 0)
		{
			printf("Error at joining thread");
			free(thread);
			return (1);
		}
		i++;
	}
	free(thread);
	return (0);
}
