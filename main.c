/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 12:14:55 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			philo_array[200];
	pthread_mutex_t	fork_array[200];
	
	check_valid_arg(argc, argv);
	store_data(++argv, &program);
	init_philo(philo_array, &program);
	init_fork(fork_array, philo_array, &program);
	return (0);
}