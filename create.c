/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/20 16:24:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_checker(t_rules *rules)
{
	if (pthread_create(&rules->id_philo[rules->amount_phil],
			NULL, &checker, rules) != 0)
		printf("ERROR could not create checker\n");
}

void	create_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL) != 0)
			printf("ERROR could init mutex\n");
		rules->philo[i].number = i + 1;
		rules->birth = get_current_time_ms();
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
	if (pthread_join(rules->id_philo[rules->amount_phil], NULL) != 0)
		printf("ERROR could not join\n");
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_destroy(&rules->forks[i]) != 0)
			printf("ERROR could not destroy mutex\n");
		i++;
	}
}

void	create(t_rules *rules)
{
	create_checker(rules);
	create_philos(rules);
	join_threads(rules);
}
	// lock_start(rules);
	// unlock_start(rules);
