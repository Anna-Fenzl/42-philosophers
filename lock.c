/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/19 12:17:05 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_start(t_rules *rules)
{
	if (pthread_mutex_init(&(rules->wait_to_start), NULL) != 0)
		printf("couldnt init wait to start\n");
	pthread_mutex_lock(&(rules->wait_to_start));
}

void	unlock_start(t_rules *rules)
{
	pthread_mutex_unlock(&(rules->wait_to_start));
	if (pthread_mutex_destroy(&(rules->wait_to_start)) != 0)
		printf("couldnt destroy wait_to_start\n");
}

void	unlock_forks(t_rules *rules)
{
	int		i;

	i = 0;
	while (i < rules->amount_phil)
	{
		if (i == 0 && rules->philo->left == true)
			pthread_mutex_unlock(&rules->forks[rules->amount_phil - 1]);
		if (rules->philo->left == true)
			pthread_mutex_unlock(&rules->forks[i]);
		if (i + 1 == rules->amount_phil && rules->philo->right == true)
			pthread_mutex_unlock(&rules->forks[0]);
		else if (rules->philo->right == true)
			pthread_mutex_unlock(&rules->forks[i + 1]);
		i++;
	}
}
