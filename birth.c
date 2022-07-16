/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/16 22:17:28 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	implement a death checker
	make all of them live longer
	try with 1 2 3 philosophers
	---> 1 segfaults in line 61
	do the must eat stuff
	cant destroy mutex cause the other one is eating rn ./philo 2  90 60 29 --> pthread_detach???
	-->fixed it with another while loop;
*/

void	take_forks_and_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", get_current_time_ms(), philo->number);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken a fork\n", get_current_time_ms(), philo->number);
	printf("%ld %d is eating ---> %i * time\n", get_current_time_ms(),
		philo->number, philo->times_eaten);
	philo->times_eaten++;
	sleep_ms(philo->data->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_nap(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_current_time_ms(), philo->number);
	if (get_current_time_ms() + philo->data->time_sleep > philo->limit)
		philo->data->death = true;
	// should i check if dead here?
	sleep_ms(philo->data->time_sleep);
}

int	check_if_dead(t_philo *philo)
{
	if (get_current_time_ms() >= philo->limit)
	{
		philo->data->death = true;
		printf("%ld %i --->DIED\n", get_current_time_ms(), philo->number);
		return (1);
	}
	return (0);
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
		philo->limit = get_current_time_ms() + philo->data->time_die;
		if (check_if_dead(philo) == 1)
			break ;
	}
	philo->data->death = true;
	return (data);
}

void	checker(t_rules *rules)
{
	sleep_ms(10);
	while (true)
	{
		if (rules->death == true)
			break ;
	}
}

void	birth_philosophers(t_rules *rules)
{
	int			i;
	pthread_t	id_philo[200];

	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL) != 0)
			ft_error(3);
		rules->philo[i].number = i + 1;
		if (pthread_create(&id_philo[i], NULL,
				&birth, &rules->philo[i]) != 0)
			ft_error(3);
		i++;
	}
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_join(id_philo[i], NULL) != 0)
			ft_error(4);
		i++;
	}
	i = 0;
	while (i < rules->amount_phil)
	{
		if (pthread_mutex_destroy(&rules->forks[i]) != 0)
			ft_error(6);
		i++;
	}
}
