/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:49:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/27 15:02:32 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	die_alone(t_philo *philo)
{
	sleep_ms(philo->data->time_die);
	printf("%ld %d died\n", timestamp(philo->data->birth), philo->number);
	exit (1);
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	if (philo->data->amount_phil == 1)
		return (die_alone(philo));
	check_if_dead(philo);
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	check_if_dead(philo);
}

void	eat(t_philo *philo)
{
	print_feedback(philo, 'e');
	if (philo->limit < get_current_time_ms() + philo->data->time_eat)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		check_if_dead(philo);
		exit (1);
	}
	sleep_ms(philo->data->time_eat);
	philo->times_eaten++;
	check_if_dead(philo);
}
