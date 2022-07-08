/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_alone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:24:16 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/08 19:02:13 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*think_and_die(void *data)
{
	t_philo		*philo;
	long		birth_time;
	int			first;

	first = 1;
	philo = (t_philo *)data;
	birth_time = get_current_time_ms();
	while (get_current_time_ms() < birth_time + philo->time_die)
	{
		if (first == 1)
		{
			printf("%li %i is thinking\n", get_current_time_ms(), philo->number);
			first = 0;
		}
	}
	printf("%li %i died\n", get_current_time_ms(), philo->number);
	return (data);
}

void	die_lonely(t_rules *rules)
{
	if (pthread_create(&rules->id_philo[0], NULL,
			&think_and_die, &rules->philo[0]) != 0)
		ft_error(3);
	if (pthread_join(rules->id_philo[0], NULL) != 0)
		ft_error(4);
}
