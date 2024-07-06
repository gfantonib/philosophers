/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_footman_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:54:47 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/06 10:27:02 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_if_dead(t_philo *philo_array);
static int	is_dead(t_philo *philo);

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
		if (is_dead(&philo_array[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	is_dead(t_philo *philo)
{	
	pthread_mutex_lock(philo->meal_mtx);
	philo->last_meal = get_current_time();
	if ((get_current_time() - philo->last_meal >= philo->time_to_die) && philo->is_eating == 0)
	{
		pthread_mutex_lock(philo->died_mtx);
		*philo->died = 1;
		print_state_change("died", philo, get_current_time());
		pthread_mutex_unlock(philo->died_mtx);
		return (pthread_mutex_unlock(philo->meal_mtx), 1);
	}
	pthread_mutex_unlock(philo->meal_mtx);
	return (0);
}