/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:49:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 18:07:14 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	die_alone(t_philo *philo)
{
	sleep_ms(philo->data->time_die);
	printf("%ld %d died\n", timestamp(philo->data->birth), philo->number);
	return (1);
}

// seems like the semaphores dont work 
// --> see 1 300 100 100 without die_alone();
int	take_forks(t_philo *philo)
{
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	if (philo->data->amount_phil == 1)
		return (die_alone(philo));
	if (check_if_dead(philo) == 1)
		return (1);
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
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
	philo->times_eaten++;
	return (must_eat(philo));
}
