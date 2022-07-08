/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:22:27 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/08 18:46:47 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_into_philo_arr(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		rules->philo[i].time_die = rules->philo[0].time_die;
		rules->philo[i].time_eat = rules->philo[0].time_eat;
		rules->philo[i].time_sleep = rules->philo[0].time_sleep;
		rules->philo[i].must_eat = rules->philo[0].must_eat;
		i++;
	}
}

void	input_check(char **input, t_rules *rules)
{
	rules->amount_phil = atoi_check(input[1]);
	rules->philo[0].time_die = atoi_check(input[2]);
	rules->philo[0].time_eat = atoi_check(input[3]);
	rules->philo[0].time_sleep = atoi_check(input[4]);
	if (input[5] != NULL)
	{
		rules->philo[0].must_eat = atoi_check(input[5]);
		if (rules->philo[0].must_eat < 0)
			ft_error(2);
	}
	else
		rules->philo[0].must_eat = -1;
	put_into_philo_arr(rules);
	if (rules->amount_phil < 1 || rules->amount_phil > 200
		|| rules->philo->time_die < 0 || rules->philo->time_eat < 0
		|| rules->philo->time_sleep < 1)
		ft_error(2);
}
