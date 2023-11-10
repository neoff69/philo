/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:31:33 by vgonnot           #+#    #+#             */
/*   Updated: 2023/11/10 13:33:47 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philo_routine(t_philo *philo, t_philo *left_philo)
{
	print_action_terminal("is thinking\n", philo);
	if (philo->nbr_philo == 1)
	{
		print_action_terminal("has taken a fork\n", philo);
		return ;
	}
	while (1)
	{
		mutex_lock(philo, left_philo);
		if (eating_routine(philo, left_philo))
			break ;
		mutex_unlock(philo, left_philo);
		if (check_stop(philo) == 1)
			break ;
		print_action_terminal("is thinking\n", philo);
		if (philo->nbr_philo % 2 == 1 && philo->who % 2 == 0)
			usleep((philo->time_eat * 0.9) * 700);
		if (philo->nbr_philo % 2 == 1 && philo->who % 2 == 1)
			usleep((philo->time_eat * 0.9) * 600);
	}
	quit_thread(philo, left_philo);
	return ;
}
