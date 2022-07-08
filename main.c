/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/08 19:14:07 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		ft_error(0);
	input_check(argv, &rules);
	printf("amount_phil =  %i\n", rules.amount_phil);
	printf("time_die    =  %li\n", rules.philo[0].time_die);
	printf("time_eat    =  %li\n", rules.philo[0].time_eat);
	printf("time_sleep  =  %li\n", rules.philo[0].time_sleep);
	printf("must_eat    = %i\n", rules.philo[0].must_eat);
	printf("\n-------------------------\n");

	if (rules.amount_phil == 1)
		die_lonely(&rules);
	else
		birth_philosophers(&rules);
	// system("leaks philo");
	return (0);
}
