/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_init_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:09:56 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 12:35:46 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(pthread_mutex_t *forks, t_philo *philos, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nbr_of_philo)
	{
		philos[i].l_fork = forks[i];
		if (i == 0)
			philos[i].r_fork = forks[program->nbr_of_philo - 1];
		else
			philos[i].r_fork = forks[i - 1];
		i++;
	}
}
