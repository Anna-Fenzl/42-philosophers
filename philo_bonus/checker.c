/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 16:07:08 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_dead(t_philo *philo)
{
	sem_wait(philo->data->lock);
	if (philo->data->death == true)
	{
		sem_post(philo->data->lock);
		return (1);
	}
	if (get_current_time_ms() >= philo->limit)
	{
		if (philo->data->death == false)
			printf("%ld %d died\n",
				timestamp(philo->data->birth), philo->number);
		philo->data->death = true;
		sem_post(philo->data->lock);
		return (1);
	}
	sem_post(philo->data->lock);
	return (0);
}
