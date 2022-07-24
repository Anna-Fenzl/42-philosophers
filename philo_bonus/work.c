/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 00:24:18 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks_and_eat(t_philo *philo)
{
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	
	return (0);
}

void	philo_start(t_philo *philo)
{
	sleep_ms(philo->data->birth - get_current_time_ms());
	print_feedback(philo, 't');
	philo->limit = get_current_time_ms() + philo->data->time_die;
	if ((philo->number & 1) == 1 && philo->data->amount_phil > 1)
		sleep_ms(3);
}
