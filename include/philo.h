/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:24:21 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/22 14:16:43 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				is_eating;
	size_t			last_meal;
	int				eaten;
	int				*died;
	int				nbr_of_philo;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	size_t			program_start;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print_mtx;
	pthread_mutex_t	*died_mtx;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	is_eating_mtx;
	pthread_mutex_t	eaten_mtx;
}	t_philo;

typedef struct s_program
{
	int				nbr_of_philo;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				died;
	size_t			program_start;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	died_mtx;
}	t_program;

// 01_check_valid_arg.c
void	check_valid_arg(int argc, char *argv[]);

// 02_store_data.c
void	store_data(char *argv[], t_program *program);

// 03_init_philo.c
void	init_philo(t_philo *philo_array, t_program *program);

// 04_init_fork.c
void	init_fork(pthread_mutex_t *forks, t_philo *philos, t_program *program);

// 05_create_thread.c
void	create_thread(t_philo *philo_array, t_program *program);

// 06_philo_routine.c
void	*philo_routine(void *arg);

// 06_utils.c
int		dead_flag_off(t_philo *philo);
void	lonely_philo(t_philo *philo);

// 07_footman_routine.c
void	*footman_routine(void *arg);

// 08_init_mutex.c
void	init_mutex(pthread_mutex_t	*fork_array);

// utils.c
void	print_message(char *message, int fd);
void	destroy_mutex(t_program *program, pthread_mutex_t *forks,
			t_philo *philo_array);
void	print_state_change(char *message, t_philo *philo, size_t time);
size_t	get_current_time(void);

// libft.c
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif