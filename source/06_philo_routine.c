/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:11:39 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/06 13:32:21 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_even(t_philo *philo);
static void	eat_odd(t_philo *philo);
static void	dream(t_philo *philo);
static int	dead_flag_off(t_philo *philo);
static void think(t_philo *philo);

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	
	philo = (t_philo *)arg;
	while (dead_flag_off(philo))
	{
		if (philo->id % 2 == 0)
			eat_even(philo);
		else
			eat_odd(philo);
		dream(philo);
		think(philo);
	}
	return (arg);
}

static int	dead_flag_off(t_philo *philo)
{
	pthread_mutex_lock(philo->died_mtx);
	if (*philo->died)
		return (pthread_mutex_unlock(philo->died_mtx), 0);
	pthread_mutex_unlock(philo->died_mtx);
	return (1);
}

static void	eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state_change("has taken r_fork", philo, get_current_time());
	pthread_mutex_lock(philo->l_fork);
	print_state_change("has taken l_fork", philo, get_current_time());
	philo->is_eating = 1;
	print_state_change("is eating", philo, get_current_time());
	pthread_mutex_lock(philo->meal_mtx);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_mtx);
	usleep(1000 * philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_state_change("has taken l_fork", philo, get_current_time());
	pthread_mutex_lock(philo->r_fork);
	print_state_change("has taken r_fork", philo, get_current_time());
	philo->is_eating = 1;
	print_state_change("is eating", philo, get_current_time());
	pthread_mutex_lock(philo->meal_mtx);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_mtx);
	usleep(1000 * philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	dream(t_philo *philo)
{
	print_state_change("is sleeping", philo, get_current_time());
	usleep(1010 * philo->time_to_sleep);
}

static void think(t_philo *philo)
{
	print_state_change("is thinking", philo, get_current_time());
}