/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 19:34:15 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	START THE DOCKER WITH ./START.SH 
	-->RUN valgrind --tool=memcheck ./philo 4 300 100 100
	-->RUN valgrind --tool=drd ./philo 4 300 100 100 
	-->RUN valgrind --tool=helgrind ./philo 4 300 100 100
		-->threads
	
	do the must eat stuff
*/

	// printf("amount_phil =  %i\n", rules.amount_phil);
	// printf("time_die    =  %li\n", rules.time_die);
	// printf("time_eat    =  %li\n", rules.time_eat);
	// printf("time_sleep  =  %li\n", rules.time_sleep);
	// printf("must_eat    = %i\n", rules.must_eat);
	// printf("\n-------------------------\n");

int	main(int argc, char **argv)
{
	t_rules	rules;

	if ((argc != 5 && argc != 6) || input_check(argv, &rules) == 1)
	{
		printf("ERROR: input not valid!\n");
		return (1);
	}
	create_philos(&rules);
	join_threads(&rules);
	free(rules.philo);
	return (0);
}
	// system("leaks philo");
