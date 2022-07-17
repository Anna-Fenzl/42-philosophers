/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:22:27 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/17 17:42:44 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_rules *rules)
{
	int		i;
	t_philo	*s;

	i = 0;
	while (i < rules->amount_phil)
	{
		s = &rules->philo[i];
		s->data = rules;
		s->times_eaten = 0;
		s->left_fork = &rules->forks[i];
		if (i == rules->amount_phil - 1)
			s->right_fork = &rules->forks[0];
		else
			s->right_fork = &rules->forks[i + 1];
		i++;
	}
}

void	input_check(char **input, t_rules *rules)
{
	rules->amount_phil = atoi_check(input[1]);
	rules->time_die = atoi_check(input[2]);
	rules->time_eat = atoi_check(input[3]);
	rules->time_sleep = atoi_check(input[4]);
	if (input[5] != NULL)
	{
		rules->must_eat = atoi_check(input[5]);
		if (rules->must_eat < 0)
			ft_error(2);
	}
	else
		rules->must_eat = -1;
	rules->death = false;
	if (rules->amount_phil >= 1)
		init(rules);
	if (rules->amount_phil < 1 || rules->amount_phil > 200
		|| rules->time_die < 0 || rules->time_eat < 0
		|| rules->time_sleep < 1)
		ft_error(2);
}
