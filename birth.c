/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/08 19:37:54 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// inplement forks
// while loop?
// check the structs to check if they died???

void	*birth(void *data)
{
	t_philo	*philo;
	int		birth_time;

	philo = (t_philo *)data;
	birth_time = get_current_time_ms();
	sleep_ms(philo->number * 1000);
	printf("%li %i is born\n", get_current_time_ms(), philo->number);
	printf("and he(%i) has this fork %i and his right\n", philo->number, philo->right_fork);
	printf("and he(%i) has this fork %i and his left\n", philo->number, philo->left_fork);
	printf("-------------------------\n");
	return (data);
}

void	birth_philosophers(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->amount_phil)
	{
		rules->philo[i].number = i;
		if (pthread_create(&rules->id_philo[i], NULL,
				&birth, &rules->philo[i]) != 0)
			ft_error(3);
		i++;
	}
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_join(rules->id_philo[i], NULL) != 0)
			ft_error(4);
		i++;
	}
}
