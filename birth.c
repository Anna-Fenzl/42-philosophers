/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:30 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/16 16:43:30 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// inplement forks
// while loop?
// check the structs to check if they died???

void	*birth(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// sleep_ms(philo->number * 1000);
	printf("%ld %d is born\n", get_current_time_ms(), philo->number);
	printf("%ld he(%i) ---->DIED\n", get_current_time_ms(), philo->number);
	return (data);
}

void	birth_philosophers(t_rules *rules)
{
	int			i;
	pthread_t	id_philo[200];

	i = 0;
	pthread_mutex_init(rules->forks, NULL);
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