/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:43:29 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/06 18:12:16 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct t_philo
{
	unsigned long int		last_meal;
	int						who;
	int						nbr_eat;
	int						pid;
}t_philo;

typedef struct t_struct
{
	int						nbr_philo;
	int						nbr_eat;
	long int				time_start;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						stop;
	struct timeval			tv;
	struct t_philo			*philo;
	sem_t					*sem_print;
	sem_t					*sem_fork;
	sem_t					*sem_queue;
}t_struct;

t_struct			set_up_struct(int argc, char **argv);
int					process_declaration(t_struct *env);
int					ft_atoi(char *str);
void				quit_function(t_struct *env, int error);
void				philo_routine(t_struct *env, t_philo *philo);
int					print_action_terminal(char *str, t_struct *env, \
					t_philo *philo, int alive);
unsigned long int	get_time(t_struct *env);
int					check_if_finish(t_struct *env, t_philo *philo);

#endif