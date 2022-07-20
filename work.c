/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/19 17:54:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// forks are not same anymore
// always take the uneven ones first
int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_feedback(philo, 'l');
	if (philo->data->amount_phil == 1)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		pthread_mutex_unlock(&philo->left_fork);
		philo->left = false;
		check_if_dead(philo);
		philo->death = true;
		return (1);
	}
	check_if_dead(philo);
	pthread_mutex_lock(&philo->right_fork);
	print_feedback(philo, 'r');
	return (0);
}

void	take_forks_and_eat(t_philo *philo)
{
	if (take_forks(philo) == 1)
		return ;
	check_if_dead(philo);
	print_feedback(philo, 'e');
	philo->times_eaten++;
	sleep_ms(philo->data->time_eat);
	pthread_mutex_unlock(&philo->left_fork);
	philo->left = false;
	pthread_mutex_unlock(&philo->right_fork);
	philo->right = false;
}

void	take_nap(t_philo *philo)
{
	print_feedback(philo, 's');
	if (philo->limit < get_current_time_ms() + philo->data->time_sleep)
	{
		sleep_ms(philo->data->time_sleep);
		check_if_dead(philo);
		return ;
	}
	sleep_ms(philo->data->time_sleep);
}

void	*work(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// sleep_ms(philo->number * 1000);
	// pthread_mutex_lock(&(philo->data->wait_to_start));
	print_feedback(philo, 't');
	printf("he(%i) has this in left %p\n", philo->number, &philo->left_fork);
	printf("he(%i) has this in right %p\n", philo->number, &philo->right_fork);
	if ((philo->number & 1) == 1)
		sleep_ms(5);
	philo->limit = get_current_time_ms() + philo->data->time_die;
	while (true)
	{
		take_forks_and_eat(philo);
		if (check_if_dead(philo) == 1)
			break ;
		take_nap(philo);
		if (check_if_dead(philo) == 1)
			break ;
		print_feedback(philo, 't');
		philo->limit = get_current_time_ms() + philo->data->time_die;
	}
	return (data);
}
