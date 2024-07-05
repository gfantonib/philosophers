/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:57:56 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 10:12:00 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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