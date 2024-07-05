/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_footman_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:54:47 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 17:36:26 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_if_dead(t_philo *philo_array);

void	*footman_routine(void *arg)
{
	t_philo *philo_array;

	philo_array = (t_philo *)arg;
	while (1)
	{
		if (check_if_dead(philo_array))
			break ;
	}
	return (arg);
}

static int check_if_dead(t_philo *philo_array)
{
	int	i;

	i = 0;
	while (i < philo_array[0].nbr_of_philo)
	{
		if ((get_current_time() - philo_array[i].last_meal >= philo_array[0].time_to_die)
			&& philo_array[i].is_eating == 0)
		{
			pthread_mutex_lock(philo_array[0].died_mtx);
			*philo_array[0].died = 1;
			print_state_change("died", &philo_array[i], get_current_time());
			pthread_mutex_unlock(philo_array[0].died_mtx);
			
			break;
		}
		i++;
	}
	return (*philo_array[0].died);
}