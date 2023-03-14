/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:43:21 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/06 17:50:43 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_struct	env;

	env = set_up_struct(argc, argv);
	if (env.stop == 1)
		return (1);
	env.stop = process_declaration(&env);
	quit_function(&env, 0);
	return (0);
}
