/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_valid_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:54:50 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/16 09:58:11 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_nbr(char *argv[]);

void	check_valid_arg(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		print_message("wrong argument count!\n", 2);
	else if (!is_valid_nbr(++argv))
		print_message("wrong argument type!\n", 2);
	else if (ft_atoi(argv[0]) > 200)
		print_message("wrong argument type!\n", 2);
	else
		return ;
	exit(1);
}

static int	is_valid_nbr(char *argv[])
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}
