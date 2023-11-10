/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:03:18 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/14 12:46:37 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct t_data{
	pthread_mutex_t			mutex_printf;
	long int				time_start;
	struct timeval			tv;
}	t_data;

typedef struct t_philo
{
	int						nbr_philo;
	int						who;
	int						stop;
	unsigned long int		last_meal;
	long int				time_start;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						nbr_eat;
	int						mid_lock;
	int						left_lock;
	pthread_mutex_t			mutex;
	pthread_mutex_t			mutex_data;
	pthread_mutex_t			mutex_fork;
	pthread_mutex_t			*mutex_printf;
	pthread_mutex_t			mutex_time;
	struct timeval			tv;
}	t_philo;

t_philo				*set_up_struct(int argc, char **argv, t_data *data);
unsigned long int	get_time(long time_start, struct timeval tv);
int					thread_declaration(t_philo *philo, t_data *data);
int					ft_atoi(char *str);
void				philo_routine(t_philo *philo, t_philo *left_philo);
int					eating_routine(t_philo *philo, t_philo *left_philo);
int					check_if_finish(t_philo *philo, t_data *data);
int					check_stop(t_philo *philo);
int					join_thread(t_philo *philo, pthread_t *thread);
int					mutex_init(t_philo *philo, t_data *data);
int					mutex_destroy(t_philo *philo);
void				mutex_lock(t_philo *philo, t_philo *left_philo);
void				mutex_unlock(t_philo *philo, t_philo *left_philo);
void				print_action_terminal( \
					char *str, t_philo *philo);
void				print_action_main(char *str, t_data *data, int who);
int					check_stop(t_philo *philo);
int					quit_thread(t_philo *philo, t_philo *left_philo);

#endif