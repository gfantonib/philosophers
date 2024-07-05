/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 11:48:50 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static void	tdd_print_store_data(t_program *program);

int	main(int argc, char *argv[])
{
	t_program program;
	
	check_valid_arg(argc, argv);
	store_data(++argv, &program);
	tdd_print_store_data(&program);
	return (0);
}

void	tdd_print_store_data(t_program *program)
{
	printf("%d |", program->nbr_of_philo);
	printf(" %d |", program->time_to_eat);
	printf(" %d |", program->time_to_die);
	printf(" %d |", program->time_to_sleep);
	printf(" %d\n", program->must_eat);
}