/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_store_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:24:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 10:47:43 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	store_data(char *argv[], t_program *program)
{
	program->nbr_of_philo = ft_atoi(argv[0]);
	program->time_to_eat = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_sleep = ft_atoi(argv[3]);
	program->must_eat = -1;
	if (argv[4])
		program->must_eat = ft_atoi(argv[4]);
}