/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:22:27 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/05 18:52:16 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	input_check(char **input, t_rules *rules)
{
	rules->num_phil = atoi_check(input[1]);
	rules->time_die = atoi_check(input[2]);
	rules->time_eat = atoi_check(input[3]);
	rules->time_sleep = atoi_check(input[4]);
	rules->must_sleep = -1;
	if (input[5] != NULL)
	{
		rules->must_sleep = atoi_check(input[5]);
		if (rules->must_sleep < 0)
			ft_error(2);
	}
	if (rules->num_phil < 1 || rules->num_phil > 200 || rules->time_die < 0
		|| rules->time_eat < 0 || rules->time_sleep < 1)
		ft_error(2);
}