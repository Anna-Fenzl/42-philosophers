/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 13:56:54 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	printf("cur: %li lim: %li\n", get_current_time_ms(), philo->limit);
	if (philo->data->death == true)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	if (get_current_time_ms() >= philo->limit)
	{
		philo->data->death = true;
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}
