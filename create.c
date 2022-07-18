/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/18 16:14:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_checker(t_rules *rules)
{
	if (pthread_create(&rules->id_philo[200], NULL, &waiter, rules) != 0)
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
		if (pthread_create(&rules->id_philo[i], NULL,
				&birth, &rules->philo[i]) != 0)
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
	if (pthread_join(rules->id_philo[200], NULL) != 0)
		ft_error(4);
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_destroy(&rules->forks[i]) != 0)
			ft_error(6);
		i++;
	}
}

	// lock_start(rules);
	// unlock_start(rules);
void	create(t_rules *rules)
{
	create_checker(rules);
	create_philos(rules);
	join_threads(rules);
}
