/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:58:12 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/24 22:56:03 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_start(t_philo *philo)
{
	sleep_ms(philo->data->birth - get_current_time_ms());
	print_feedback(philo, 't');
	return ;
}
