/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:44:20 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/06 13:37:38 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

static int	check_arg_error(t_struct *env)
{
	int	return_value;

	return_value = 0;
	if (env->nbr_philo < 1)
		return_value = printf("No philosopher\n");
	else if (env->time_die < 0 \
			|| env->time_eat < 0 || env->time_sleep < 0)
		return_value = printf("Error : arguments\n");
	else if (env->nbr_eat == -1)
		return_value = printf("Error : arguments\n");
	else if (env->nbr_eat == 0)
		return_value = 1;
	if (return_value != 0)
	{
		env->stop = 1;
		return (1);
	}
	return (0);
}

void	set_up_value_env(int argc, char **argv, t_struct *env)
{
	env->stop = 0;
	env->nbr_philo = ft_atoi(argv[1]);
	env->time_die = ft_atoi(argv[2]);
	env->time_eat = ft_atoi(argv[3]);
	env->time_sleep = ft_atoi(argv[4]);
	env->sem_fork = NULL;
	env->sem_print = NULL;
	if (argc == 6)
			env->nbr_eat = ft_atoi(argv[5]);
	else
		env->nbr_eat = -2;
	gettimeofday(&env->tv, NULL);
	env->time_start = 1000000 * env->tv.tv_sec \
							+ env->tv.tv_usec;
}

void	set_up_value_philo(t_struct *env)
{
	int		i;

	env->philo = malloc(sizeof(t_philo) * env->nbr_philo);
	if (env->philo == NULL)
	{
		env->stop = 1;
		return ;
	}
	i = 0;
	while (i < env->nbr_philo)
	{
		env->philo[i].last_meal = 0;
		env->philo[i].who = i + 1;
		env->philo[i].nbr_eat = env->nbr_eat;
		i++;
	}
}

int	check_nbr_arg_error(int argc, t_struct *env)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error : arguments\n");
		env->stop = 1;
		return (1);
	}
	return (0);
}

t_struct	set_up_struct(int argc, char **argv)
{
	t_struct	env;

	if (check_nbr_arg_error(argc, &env))
		return (env);
	set_up_value_env(argc, argv, &env);
	if (check_arg_error(&env))
		return (env);
	set_up_value_philo(&env);
	return (env);
}
