/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/16 20:53:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks_and_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", get_current_time_ms(), philo->number);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken a fork\n", get_current_time_ms(), philo->number);
	printf("%ld %d is eating ---> %i * time\n", get_current_time_ms(), philo->number, philo->times_eaten);
	philo->times_eaten++;
	sleep_ms(philo->data->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_nap(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_current_time_ms(), philo->number);
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
		if (check_if_dead(philo) == 1)
			break ;
		philo->limit = get_current_time_ms() + philo->data->time_die;
		if (check_if_dead(philo) == 1)
			break ;
	}
	return (data);
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
		i++;
	}
	i = 0;
	while (i < rules->amount_phil)
	{
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
	pthread_mutex_destroy(rules->forks);
}

	// sleep_ms(philo->number * 100);
	// printf("he (%i) has this time to die %li\n", philo->number, philo->data->time_die);
	// printf("he (%i) has this time to eat %li\n", philo->number, philo->data->time_eat);
	// printf("he (%i) has this time to sleep %li\n", philo->number, philo->data->time_sleep);
	// printf("he (%i) has this time he must eat %i\n", philo->number, philo->data->must_eat);
	// printf("he (%i) has in his left %p\n", philo->number, philo->left_fork);
	// printf("he (%i) has in his right %p\n", philo->number, philo->right_fork);
	// printf("he (%i) time_die is %li\n", philo->number, philo->data->time_die);
	// printf("he (%i) time_eat is %li\n", philo->number, philo->data->time_eat);
	// printf("he (%i) time_sleep die is %li\n", philo->number, philo->data->time_sleep);
	// printf("he (%i) must_eat is %i\n", philo->number, philo->data->must_eat);
	// philo->last_meal = get_current_time_ms();
	// philo->limit = philo->last_meal + philo->data->time_die;
	// printf("%ld %d is born\n", get_current_time_ms(), philo->number);
	// while (get_current_time_ms() < philo->limit)
	// {
	// 	cotinue ;
	// }