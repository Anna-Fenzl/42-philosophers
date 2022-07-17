/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/17 17:46:53 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	START THE DOCKER WITH ./START.SH 
	-->RUN valgrind --tool=memcheck ./philo 4 300 100 100
	-->RUN valgrind --tool=drd ./philo 4 300 100 100 
	-->RUN valgrind --tool=helgrind ./philo 4 300 100 100
	
	start time from 00000000
	check for death or unlock fork if i cant take second one
	let them start at the same time
	logic for 1 2 3 philos
	make all of them live longer
	do the must eat stuff
	// one philosopher
*/

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken left fork\n", get_current_time_ms(), philo->number);
	if (philo->data->amount_phil == 1)
	{
		sleep_ms(philo->limit - get_current_time_ms());
		check_if_dead(philo);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken right fork\n", get_current_time_ms(), philo->number);
	return (0);
}

void	take_forks_and_eat(t_philo *philo)
{
	if (take_forks(philo) == 1)
		return ;
	printf("%ld %d is eating ---> %i * time\n", get_current_time_ms(),
		philo->number, philo->times_eaten);
	philo->times_eaten++;
	sleep_ms(philo->data->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

// need to check if its gonna die while sleep
void	take_nap(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_current_time_ms(), philo->number);
	if (philo->limit < get_current_time_ms() + philo->data->time_sleep)
	{
		sleep_ms(philo->data->time_sleep);
		check_if_dead(philo);
		return ;
	}
	sleep_ms(philo->data->time_sleep);
}

void	*birth(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("%ld %d is thinking\n", get_current_time_ms(), philo->number);
	if ((philo->number & 1) == 1)
		sleep_ms(5);
	philo->limit = get_current_time_ms() + philo->data->time_die;
	while (true)
	{
		take_forks_and_eat(philo);
		if (check_if_dead(philo) == 1)
			break ;
		take_nap(philo);
		if (check_if_dead(philo) == 1)
			break ;
		printf("%ld %d is thinking\n", get_current_time_ms(), philo->number);
		philo->limit = get_current_time_ms() + philo->data->time_die;
	}
	return (data);
}

void	birth_philosophers(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_create(&rules->id_philo[200], NULL, &waiter, rules) != 0)
		ft_error(3);
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL) != 0)
			ft_error(3);
		rules->philo[i].number = i + 1;
		if (pthread_create(&rules->id_philo[i], NULL,
				&birth, &rules->philo[i]) != 0)
			ft_error(3);
		i++;
	}
	if (pthread_join(rules->id_philo[200], NULL) != 0)
		ft_error(4);
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_join(rules->id_philo[i], NULL) != 0)
			ft_error(4);
		i++;
	}
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_destroy(&rules->forks[i]) != 0)
			ft_error(6);
		i++;
	}
}
