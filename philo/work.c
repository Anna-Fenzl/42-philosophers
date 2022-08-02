/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/08/02 17:28:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_nap(t_philo *philo)
{
	print_feedback(philo, nap);
	if (philo->limit <= get_current_time_ms() + philo->data->time_sleep)
	{
		while (get_current_time_ms() <= philo->limit)
			continue ;
		check_if_dead(philo);
		return (1);
	}
	sleep_ms(philo->data->time_sleep);
	return (0);
}

int	take_forks_and_eat(t_philo *philo)
{
	if (philo->data->amount_phil == 1)
		return (die_alone(philo));
	if (who_takes_forks(philo) == 1)
		return (1);
	if (eating(philo) == 1)
	{
		unlock_both_forks(philo);
		return (1);
	}
	unlock_both_forks(philo);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_feedback(philo, think);
	if (philo->limit <= get_current_time_ms() + philo->data->time_eat)
	{
		while (get_current_time_ms() <= philo->limit)
			continue ;
		check_if_dead(philo);
		return (1);
	}
	if ((philo->data->amount_phil & 1) == 1)
		sleep_ms(philo->data->time_eat);
	return (check_if_dead(philo));
}

void	*work(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	sleep_ms(philo->data->birth - get_current_time_ms());
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->death == false)
		printf("%li %i is thinking\n",
			timestamp(philo->data->birth), philo->number);
	pthread_mutex_unlock(&philo->data->lock);
	philo->limit = get_current_time_ms() + philo->data->time_die;
	if ((philo->number & 1) == 1 && philo->data->amount_phil > 1)
		sleep_ms(3);
	while (true)
	{
		if (take_forks_and_eat(philo) == 1)
			return (data);
		philo->limit = get_current_time_ms() + philo->data->time_die;
		if (take_nap(philo) == 1)
		{
			return (data);
		}
		if (thinking(philo) == 1)
			return (data);
	}
}
