/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 11:30:07 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static void	tdd_print_philo_id(t_philo *philo, t_program *program);

int	main(int argc, char *argv[])
{
	t_program	program;
	t_philo		philo_array[200];
	
	check_valid_arg(argc, argv);
	store_data(++argv, &program);
	init_philo(philo_array, &program);
	tdd_print_philo_id(philo_array, &program);
	return (0);
}

void	tdd_print_philo_id(t_philo *philo_array, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nbr_of_philo)
	{
		printf("%d ", philo_array[i].id);
		i++;
	}
	printf("\n");
}