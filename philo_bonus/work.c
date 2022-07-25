/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 15:57:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks_and_eat(t_philo *philo)
{
	if (take_forks(philo) == 1)
		return (1);
	if (eat(philo) == 1)
		return (1);
	sem_post(philo->data->num_forks);
	sem_post(philo->data->num_forks);
	return (0);
}

int	take_nap(t_philo *philo)
{
	print_feedback(philo, 's');
	if (philo->limit < get_current_time_ms() + philo->data->time_sleep)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		check_if_dead(philo);
		return (1);
	}
	sleep_ms(philo->data->time_sleep);
	return (check_if_dead(philo));
}

int	thinking(t_philo *philo)
{
	print_feedback(philo, 't');
	if (philo->limit <= get_current_time_ms() + philo->data->time_eat)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		check_if_dead(philo);
		return (1);
	}
	sleep_ms(philo->data->time_eat);
	return (check_if_dead(philo));
}

void	philo_start(t_philo *philo)
{
	sleep_ms(philo->data->birth - get_current_time_ms());
	print_feedback(philo, 't');
	philo->limit = get_current_time_ms() + philo->data->time_die;
	if ((philo->number & 1) == 1 && philo->data->amount_phil > 1)
		sleep_ms(philo->data->time_eat);
	while (true)
	{
		if (take_forks_and_eat(philo) == 1)
			return ;
		if (take_nap(philo) == 1)
			return ;
		if (thinking(philo) == 1)
			return ;
		philo->limit = get_current_time_ms() + philo->data->time_die;
	}
}
