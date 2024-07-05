/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:11:39 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 10:36:08 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo);

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	eat(philo);
	return (arg);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state_change("has taken r_fork", philo, get_current_time());
	pthread_mutex_lock(philo->l_fork);
	print_state_change("has taken l_fork", philo, get_current_time());
	philo->is_eating = 1;
	print_state_change("is eating", philo, get_current_time());
	usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}