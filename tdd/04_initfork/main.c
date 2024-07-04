/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 14:12:16 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static void	tdd_print_fork_sequence(t_philo *philo_array, t_program *program);

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			philo_array[200];
	pthread_mutex_t	fork_array[200];
	
	check_valid_arg(argc, argv);
	store_data(++argv, &program);
	init_philo(philo_array, &program);
	init_fork(fork_array, philo_array, &program);
	tdd_print_fork_sequence(philo_array, &program);
	return (0);
}

void	tdd_print_fork_sequence(t_philo *philo_array, t_program *program)
{
	int	i;
	char *flag;
	
	i = 0;
	flag = "ok";
	while (i < program->nbr_of_philo - 1)
	{
		// printf("%p = %p\n", philo_array[i].l_fork, philo_array[i + 1].r_fork);
		if (philo_array[i].l_fork != philo_array[i + 1].r_fork)
			flag = "ko";
		i++;
	}
	if (philo_array[i].l_fork != philo_array[0].r_fork)
		flag = "ko";
	// printf("%p = %p\n", philo_array[i].l_fork, philo_array[0].r_fork);
	printf("%s\n", flag);
}