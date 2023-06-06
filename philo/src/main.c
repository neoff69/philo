/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:59:58 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/22 08:29:44 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;

	philo = set_up_struct(argc, argv, &data);
	if (philo == NULL)
		return (1);
	else if (thread_declaration(philo, &data))
	{
		free(philo);
		return (-1);
	}
	free(philo);
	return (0);
}
