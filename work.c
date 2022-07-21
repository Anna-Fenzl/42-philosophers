/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 13:58:16 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// forks are not same anymore --> they are again
// always take the uneven ones first

void	*work(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (get_current_time_ms() < philo->data->birth)
		continue ;
	while (true)
	{
		philo->limit = get_current_time_ms() + philo->data->time_die;
		if (print_feedback(philo, 't') == 1)
			return (data);
		if (take_forks_and_eat(philo) == 1)
			return (data);
	}
}
