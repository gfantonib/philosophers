/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:04:52 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 19:06:19 by gfantoni         ###   ########.fr       */
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
		philo_array[i].print_mtx = &program->print_mtx;
		philo_array[i].is_eating = -1;
		i++;
	}
}