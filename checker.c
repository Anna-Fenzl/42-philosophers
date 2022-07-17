/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/17 15:21:38 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// thread that constantly checks if dead
void	*waiter(void *data)
{
	t_rules	*rules;
	int		i;

	i = 0;
	rules = (t_rules *)data;
	sleep_ms(10);
	while (true)
	{
		if (rules->death == true)
		{
			while (i < rules->amount_phil)
			{
				pthread_mutex_unlock(&rules->forks[i]);
				i++;
			}
			return (data);
		}
	}
}

int	check_if_dead(t_philo *philo)
{
	if (philo->data->death == true)
		return (1);
	else if (get_current_time_ms() >= philo->limit)
	{
		printf("%ld %i --->DIED\n", get_current_time_ms(), philo->number);
		philo->data->death = true;
		return (1);
	}
	return (0);
}
