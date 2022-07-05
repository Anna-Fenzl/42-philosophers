/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/05 21:46:57 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("hello from philo number %i\n", philo->number);
	return (data);
}

void	birth_philosophers(t_rules *rules)
{
	int			i;

	i = 0;
	while (i < rules->num_phil)
	{
		rules->philosopher[i].number = i;
		if (pthread_create(&rules->philo[i], NULL, &routine, &rules->philosopher[i]) != 0)
			ft_error(3);
		i++;
	}
	i = 0;
	while (i < rules->num_phil)
	{
		if (pthread_join(rules->philo[i], NULL) != 0)
			ft_error(4);
		printf("thread %i has finsihed execution\n", i);
		i++;
	}
	
}
