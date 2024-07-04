/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:57:56 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 19:51:46 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(philo->r_fork);
	print_state_change("has taken r_fork", philo);
	pthread_mutex_lock(philo->l_fork);
	print_state_change("has taken l_fork", philo);
	philo->is_eating = philo->id;
	print_state_change("is eating", philo);
	printf("%d\n", philo->is_eating);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (arg);
}

void	create_thread(t_philo *philo_array, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nbr_of_philo)
	{
		pthread_create(&philo_array[i].thread, NULL, &philo_routine, &philo_array[i]);
		i++;
	}
	i = 0;
	while (i < program->nbr_of_philo)
	{
		pthread_join(philo_array[i].thread, NULL);
		i++;
	}
}