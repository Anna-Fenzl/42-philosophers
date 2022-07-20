/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/19 17:48:38 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// thread that constantly checks if dead
	// while loop is inefficient--> use a lock for rules->death 
	// need to unlock the threads in themselfes
void	*checker(void *data)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)data;
	sleep_ms(5);
	while (true)
	{
		i = 0;
		while (i < rules->amount_phil)
		{
			if (rules->philo[i].death == true)
			{
				return (data);
			}
			i++;
		}
	}
}

int	check_if_dead(t_philo *philo)
{
	if (philo->death == true)
		return (1);
	else if (get_current_time_ms() >= philo->limit)
	{
		print_feedback(philo, 'd');
		philo->death = true;
		return (1);
	}
	return (0);
}
