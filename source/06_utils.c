/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:05:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/06 16:06:52 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_flag_off(t_philo *philo)
{
	pthread_mutex_lock(philo->died_mtx);
	if (*philo->died)
		return (pthread_mutex_unlock(philo->died_mtx), 0);
	pthread_mutex_unlock(philo->died_mtx);
	return (1);
}

void	lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state_change("has taken r_fork", philo, get_current_time());
	usleep(1000 * philo->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
}
