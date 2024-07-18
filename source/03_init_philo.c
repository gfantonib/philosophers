/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:04:52 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/18 09:37:11 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo_array, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nbr_of_philo)
	{
		philo_array[i].id = i + 1;
		philo_array[i].is_eating = 0;
		philo_array[i].last_meal = get_current_time() - program->program_start;
		philo_array[i].eaten = 0;
		philo_array[i].died = &program->died;
		philo_array[i].nbr_of_philo = program->nbr_of_philo;
		philo_array[i].time_to_eat = program->time_to_eat;
		philo_array[i].time_to_die = program->time_to_die;
		philo_array[i].time_to_sleep = program->time_to_sleep;
		philo_array[i].must_eat = program->must_eat;
		philo_array[i].program_start = program->program_start;
		philo_array[i].print_mtx = &program->print_mtx;
		philo_array[i].died_mtx = &program->died_mtx;
		pthread_mutex_init(&philo_array[i].meal_mtx, NULL);
		pthread_mutex_init(&philo_array[i].is_eating_mtx, NULL);
		i++;
	}
}
