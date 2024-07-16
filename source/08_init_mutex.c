/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:22:15 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/16 14:23:15 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(pthread_mutex_t	*fork_array)
{
	int	i;

	i = 0;
	while (i < 200)
	{
		pthread_mutex_init(&fork_array[i], NULL);
		i++;
	}
}
