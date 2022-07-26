/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:49:36 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/26 16:10:54 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	die_alone(t_philo *philo)
{
	sleep_ms(philo->data->time_die);
	printf("%ld %d died\n", timestamp(philo->data->birth), philo->number);
	exit (1);
}

// seems like the semaphores dont work 
// --> see 1 300 100 100 without die_alone();
void	take_forks(t_philo *philo)
{
	int	value;

	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	{
		if (sem_getvalue(philo->data->num_forks, &value) == -1)
			printf("sem_getvalue\n");
		printf("\n \nVALUE OF THE SEMAPHORE FORKS --> %d\n", value);
	}
	if (philo->data->amount_phil == 1)
		return (die_alone(philo));
	check_if_dead(philo);
	sem_wait(philo->data->num_forks);
	print_feedback(philo, 'f');
	{
		if (sem_getvalue(philo->data->num_forks, &value) == -1)
			printf("sem_getvalue\n");
		printf("\n \nVALUE OF THE SEMAPHORE FORKS --> %d\n", value);
	}
	check_if_dead(philo);
}

void	eat(t_philo *philo)
{
	print_feedback(philo, 'e');
	if (philo->limit < get_current_time_ms() + philo->data->time_eat)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		check_if_dead(philo);
		exit (1);
	}
	sleep_ms(philo->data->time_eat);
	philo->times_eaten++;
	check_if_dead(philo);
	must_eat(philo);
}
