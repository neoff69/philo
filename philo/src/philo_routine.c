/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:31:33 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/22 14:11:55 by vgonnot          ###   ########.fr       */
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
		if (philo->nbr_philo == 3 && philo->who == 3)
			usleep((philo->time_eat * 0.9) * 700);
		if (philo->nbr_philo == 3 && philo->who == 2)
			usleep((philo->time_eat * 0.9) * 600);
		mutex_lock(philo, left_philo);
		if (eating_routine(philo, left_philo))
			break ;
		mutex_unlock(philo, left_philo);
		if (check_stop(philo) == 1)
			break ;
		print_action_terminal("is thinking\n", philo);
	}
	quit_thread(philo, left_philo);
	return ;
}
