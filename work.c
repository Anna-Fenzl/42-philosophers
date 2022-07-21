/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 19:20:50 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_nap(t_philo *philo)
{
	print_feedback(philo, 's');
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
	if (eat(philo) == 1)
	{
		unlock_both_forks(philo);
		return (1);
	}
	unlock_both_forks(philo);
	return (0);
}

void	*work(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (get_current_time_ms() < philo->data->birth)
		continue ;
	philo->limit = get_current_time_ms() + philo->data->time_die;
	if ((philo->number & 1) == 1 && philo->data->amount_phil > 1)
		sleep_ms(2);
	while (true)
	{
		if (print_feedback(philo, 't') == 1)
			return (data);
		if (take_forks_and_eat(philo) == 1)
			return (data);
		philo->limit = get_current_time_ms() + philo->data->time_die;
		if (take_nap(philo) == 1)
		{
			return (data);
		}
	}
}
