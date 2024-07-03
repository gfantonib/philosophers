/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:24:21 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/03 17:39:02 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
// # include <stdarg.h>

// 01_check_valid_arg.c
void	check_valid_arg(int argc, char *argv[]);

// utils_1.c
void	print_message(char *message, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif