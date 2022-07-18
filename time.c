/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:18:06 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/18 16:36:00 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	timestamp(long birth)
{
	return (get_current_time_ms() - birth);
}

long	get_current_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	sleep_ms(int ms)
{
	long	start;

	start = get_current_time_ms();
	while (start + ms > get_current_time_ms())
		usleep(500);
}
