/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/08 16:26:29 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*birth(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	sleep_ms(philo->number * philo->time_sleep);
	printf("%li %i is born\n", get_current_time_ms(), philo->number);
	return (data);
}

void	birth_philosophers(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		rules->philo[i].number = i;
		if (pthread_create(&rules->id_philo[i],
				NULL, &birth, &rules->philo[i]) != 0)
			ft_error(3);
		i++;
	}
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_join(rules->id_philo[i], NULL) != 0)
			ft_error(4);
		// printf("thread %i has finsihed execution\n", i);
		i++;
	}
}
