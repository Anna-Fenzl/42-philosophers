/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/19 14:24:50 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_checker(t_rules *rules)
{
	if (pthread_create(&rules->id_philo[rules->amount_phil],
			NULL, &waiter, rules) != 0)
		ft_error(3);
}

void	create_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL) != 0)
			ft_error(3);
		rules->philo[i].number = i + 1;
		rules->birth = get_current_time_ms();
		if (pthread_create(&rules->id_philo[i], NULL,
				&work, &rules->philo[i]) != 0)
			ft_error(3);
		i++;
	}
}

void	join_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_join(rules->id_philo[i], NULL) != 0)
			ft_error(4);
		i++;
	}
	if (pthread_join(rules->id_philo[rules->amount_phil], NULL) != 0)
		ft_error(4);
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_destroy(&rules->forks[i]) != 0)
			ft_error(6);
		i++;
	}
}

void	create(t_rules *rules)
{
	create_checker(rules);
	// lock_start(rules);
	create_philos(rules);
	join_threads(rules);
	// unlock_start(rules);
}
