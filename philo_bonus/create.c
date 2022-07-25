/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 16:17:22 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	open_semaphores(t_rules *rules)
{
	rules->num_forks = sem_open("/forks",
			O_CREAT, S_IRUSR | S_IWUSR, rules->amount_phil);
	rules->lock = sem_open("/lock",
			O_CREAT, S_IRUSR | S_IWUSR, 1);
}

void	create_philos(t_rules *rules)
{
	int	i;

	i = 0;
	rules->birth = get_current_time_ms() + 35;
	while (i < rules->amount_phil)
	{
		rules->id_philo[i] = fork();
		if (rules->id_philo[i] == -1)
		{
			printf("fork mistake here (%i)\n", i);
			return ;
		}
		if (rules->id_philo[i] == 0)
		{
			rules->philo[i].number = i + 1;
			philo_start(&rules->philo[i]);
			return ;
		}
		i++;
	}
}

void	wait_for_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		waitpid(rules->id_philo[i], NULL, 0);
		i++;
	}
	sem_close(rules->lock);
	sem_close(rules->num_forks);
}

void	create(t_rules *rules)
{
	open_semaphores(rules);
	create_philos(rules);
	wait_for_philos(rules);
}
