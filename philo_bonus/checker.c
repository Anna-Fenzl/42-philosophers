/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:02:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/26 16:47:55 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_dead(t_philo *philo)
{
	if (get_current_time_ms() >= philo->limit)
	{	
		printf("%ld %d died\n",
			timestamp(philo->data->birth), philo->number);
		exit(1);
	}
	philo->data->death = sem_open("not_existing", S_IRUSR | S_IWUSR, 0);
	if (philo->data->death != SEM_FAILED)
		exit (1);
}

void	must_eat(t_philo *philo)
{
	if (philo->times_eaten == philo->data->must_eat)
		exit (1);
}
