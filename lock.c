/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 13:53:03 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	unlock_both_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
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
