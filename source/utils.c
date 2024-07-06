/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:44:26 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/06 16:12:16 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *message, int fd)
{
	int	len;

	len = ft_strlen(message);
	write(fd, message, len);
}

void	destroy_mutex(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	pthread_mutex_destroy(&program->print_mtx);
	pthread_mutex_destroy(&program->died_mtx);
	i = 0;
	while (i < program->nbr_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	print_state_change(char *message, t_philo *philo, size_t time)
{
	if (*philo->died)
		return ;
	pthread_mutex_lock(philo->print_mtx);
	printf("%ldms %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(philo->print_mtx);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
