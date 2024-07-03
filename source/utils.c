/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:44:26 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/03 17:38:40 by gfantoni         ###   ########.fr       */
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