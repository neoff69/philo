/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:31:33 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/01 13:52:18 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philo_routine(t_philo *philo, t_philo *left_philo)
{
	if (philo->nbr_philo == 1)
	{
		print_action_terminal("is thinking\n", philo);
		return ;
	}
	while (1)
	{
		print_action_terminal("is thinking\n", philo);
		mutex_lock(philo, left_philo);
		if (eating_routine(philo, left_philo))
			break ;
		mutex_unlock(philo, left_philo);
		if (check_stop(philo) == 1)
			break ;
		if (check_stop(philo) == 1)
			break ;
	}
	quit_thread(philo, left_philo);
	return ;
}
