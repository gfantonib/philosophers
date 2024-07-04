/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:24:21 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/04 11:19:55 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
}	t_philo;

typedef struct s_program
{
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_program;

// 01_check_valid_arg.c
void	check_valid_arg(int argc, char *argv[]);

// 02_store_data.c
void	store_data(char *argv[], t_program *program);

// 03_init_philo.c
void	init_philo(t_philo *philo_array, t_program *program);

// utils_1.c
void	print_message(char *message, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif