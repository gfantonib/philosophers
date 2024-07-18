/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_footman_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:54:47 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/18 09:44:19 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_if_dead(t_philo *philo_array);
static int	is_dead(t_philo *philo);
static int	check_if_satisfied(t_philo *philo_array);

void	*footman_routine(void *arg)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)arg;
	while (1)
	{
		if (check_if_dead(philo_array))
			break ;
		else if (check_if_satisfied(philo_array))
			break ;
	}
	return (arg);
}

static int	check_if_dead(t_philo *philo_array)
{
	int	i;

	i = 0;
	while (i < philo_array[0].nbr_of_philo)
	{
		if (is_dead(&philo_array[i]))
		{
			print_state_change("died", &philo_array[i], get_current_time() - philo_array[0].program_start);
			pthread_mutex_lock(philo_array[0].died_mtx);
			*philo_array[0].died = 1;
			pthread_mutex_unlock(philo_array[0].died_mtx);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	pthread_mutex_lock(&philo->is_eating_mtx);
	if (((get_current_time() - philo->program_start) - philo->last_meal >= philo->time_to_die)
		&& philo->is_eating == 0)
	{
		pthread_mutex_unlock(&philo->is_eating_mtx);
		pthread_mutex_unlock(&philo->meal_mtx);
		return (1);
	}
	pthread_mutex_unlock(&philo->is_eating_mtx);
	pthread_mutex_unlock(&philo->meal_mtx);
	return (0);
}

static int	check_if_satisfied(t_philo *philo_array)
{
	int	i;

	i = 0;
	while (i < philo_array[0].nbr_of_philo)
	{
		if (philo_array[i].eaten != philo_array[0].must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(philo_array[0].died_mtx);
	*philo_array[0].died = 1;
	pthread_mutex_unlock(philo_array[0].died_mtx);
	return (1);
}
