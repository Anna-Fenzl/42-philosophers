/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:49:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 13:56:02 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	die_alone(t_philo *philo)
{
	print_feedback(philo, 'l');
	sleep_ms(philo->data->time_die);
	print_feedback(philo, 'd');
	return (1);
}

// printf wich for just for debug reasons
int	take_forks(t_philo *philo)
{
	if ((philo->number & 1) == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_feedback(philo, 'l');
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_feedback(philo, 'r');
	}
	if (check_if_dead(philo) == 1)
		return (1);
	if ((philo->number & 1) == 1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_feedback(philo, 'r');
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_feedback(philo, 'l');
	}
	return (check_if_dead(philo));
}

int	eat(t_philo *philo)
{
	print_feedback(philo, 'e');
	sleep_ms(philo->data->time_eat);
	philo->times_eaten++;
	return (check_if_dead(philo));
}

int	take_forks_and_eat(t_philo *philo)
{
	if (philo->data->amount_phil == 1)
		return (die_alone(philo));
	if (take_forks(philo) == 1)
		return (1);
	if (eat(philo) == 1)
		return (1);
	unlock_both_forks(philo);
	return (0);
}
