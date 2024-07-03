/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:46:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/02 22:14:49 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_valid_arg(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	check_valid_arg(argc, argv);
	return (0);
}

static void	check_valid_arg(int argc, char *argv[])
{
	argc = 0;
	argv = NULL;
	printf("argc = %d | argv = %p\n", argc, argv);
}