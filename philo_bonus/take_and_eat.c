/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:49:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 15:40:40 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_philo *philo)
{
	if (philo->number == 1)
	{
		sem_wait(philo->data->num_forks);
		print_feedback(philo, 'f');
		if (check_if_dead(philo) == 1)
			return (1);
		sem_wait(philo->data->num_forks);
		print_feedback(philo, 'f');
	}
	return (check_if_dead(philo));
}

int	eat(t_philo *philo)
{
	print_feedback(philo, 'e');
	if (philo->limit < get_current_time_ms() + philo->data->time_eat)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		check_if_dead(philo);
		return (1);
	}
	sleep_ms(philo->data->time_eat);
	return (0);
}
