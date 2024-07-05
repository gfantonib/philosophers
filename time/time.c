/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:36:15 by gfantoni          #+#    #+#             */
/*   Updated: 2024/07/05 16:11:17 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

size_t	get_current_time(void);

int main(void)
{
	struct timeval	time_struct;
	int 			time;
	size_t 			sec;
	size_t 			microsec;

	// microsec = get_current_time();
	time = gettimeofday(&time_struct, NULL);
	sec = time_struct.tv_sec;
	microsec = time_struct.tv_usec;
	
	printf("sec = %zu\n", sec);
	printf("microsec = %zu\n", microsec);
	// printf("time2 = %zu\n", time2);

}

size_t	get_current_time(void)
{
	struct timeval	time_struct;

	if (gettimeofday(&time_struct, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time_struct.tv_sec * 1000 + time_struct.tv_usec / 1000);
}