/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 19:36:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->death == true)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	if (get_current_time_ms() >= philo->limit)
	{
		philo->data->death = true;
		printf("%ld %d died\n",
			timestamp(philo->data->birth), philo->number);
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

int	must_eat_checker(t_philo *philo)
{
	if (philo->times_eaten == philo->data->must_eat)
		return (1);
	return (0);
}
