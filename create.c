/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 12:08:20 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philos(t_rules *rules)
{
	int	i;

	i = 0;
	rules->birth = get_current_time_ms() + 3;
	if (pthread_mutex_init(&(rules->lock), NULL) != 0)
		printf("ERROR could init mutex (lock)\n");
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL) != 0)
			printf("ERROR could init mutex\n");
		rules->philo[i].number = i + 1;
		if (pthread_create(&rules->id_philo[i], NULL,
				&work, &rules->philo[i]) != 0)
			printf("ERROR could not create philos\n");
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
			printf("ERROR could not join\n");
		i++;
	}
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_destroy(&(rules->forks[i])) != 0)
			printf("ERROR could not destroy mutex\n");
		i++;
	}
	if (pthread_mutex_destroy(&(rules->lock)) != 0)
		printf("ERROR could not destroy mutex (lock)\n");
}

void	create(t_rules *rules)
{
	create_philos(rules);
	join_threads(rules);
}
