/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:29:07 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/11 15:55:24 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checker(t_rules *rules)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < rules->amount_phil)
		{
			if (rules->philo[i].died == 1)
			{
				printf("THIS ENDS HERE\n");
				exit(0);
			}
			i++;
		}
		i = 0;
	}
}

// if philo_must eat > 0
void	must_eat_checker(t_rules *rules)
{
	int	i;
	int	all_ate;

	while (1)
	{
		i = 0;
		all_ate = 0;
		while (i < rules->amount_phil)
		{
			// if (rules->philo[i].died == 1)
			// {
			// 	printf("THIS ENDS HERE\n");
			// 	exit(0);
			// }
			if (rules->philo[i].must_eat == 0)
				all_ate++;
			i++;
		}
		if (all_ate == rules->amount_phil)
			exit(0);
	}
}
