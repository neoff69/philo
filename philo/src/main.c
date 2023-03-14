/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:59:58 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/28 09:14:28 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = set_up_struct(argc, argv);
	if (philo == NULL)
		return (1);
	else if (thread_declaration(philo))
	{
		free(philo);
		return (-1);
	}
	free(philo);
	return (0);
}
