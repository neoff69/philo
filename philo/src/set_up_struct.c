/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:44:20 by vgonnot           #+#    #+#             */
/*   Updated: 2023/02/28 08:54:34 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	check_arg_error(t_philo *philo)
{
	int	return_value;

	return_value = 0;
	if (philo->nbr_philo < 1)
		return_value = printf("No philosopher\n");
	else if (philo->time_die < 0 \
			|| philo->time_eat < 0 || philo->time_sleep < 0)
		return_value = printf("Error : arguments\n");
	else if (philo->nbr_eat == -1)
		return_value = printf("Error : arguments\n");
	else if (philo->nbr_eat == 0)
		return_value = 1;
	if (return_value != 0)
		return (free(philo), 1);
	return (0);
}

void	set_up_all_value(int argc, char **argv, t_philo *philo, int nbr_philo)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		philo[i].who = i + 1;
		philo[i].stop = 0;
		philo[i].mid_lock = 0;
		philo[i].left_lock = 0;
		philo[i].nbr_philo = ft_atoi(argv[1]);
		philo[i].time_die = ft_atoi(argv[2]);
		philo[i].time_eat = ft_atoi(argv[3]);
		philo[i].time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo[i].nbr_eat = ft_atoi(argv[5]);
		else
			philo[i].nbr_eat = -2;
		gettimeofday(&philo[i].tv, NULL);
		philo[i].time_start = 1000000 * philo[i].tv.tv_sec \
								+ philo[i].tv.tv_usec;
		philo[i].last_meal = 0;
		i++;
	}
}

t_philo	*set_up_struct(int argc, char **argv)
{
	t_philo	*philo;
	int		nbr_philo;

	if (argc < 5 || argc > 6)
	{
		printf("Error : arguments\n");
		return (NULL);
	}
	nbr_philo = ft_atoi(argv[1]);
	if (nbr_philo < 0)
	{
		printf("Error : arguments\n");
		return (NULL);
	}
	philo = malloc(sizeof(t_philo) * nbr_philo);
	if (philo == NULL)
		return (NULL);
	set_up_all_value(argc, argv, philo, nbr_philo);
	if (check_arg_error(&philo[0]))
		return (NULL);
	return (philo);
}
