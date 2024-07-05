/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:44:26 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 14:52:58 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *message, int fd)
{
	int len;

	len = ft_strlen(message);
	write(fd, message, len);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	if (*str == '\0')
		return (0);
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	is_neg = 1;
	if (str[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str [i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
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