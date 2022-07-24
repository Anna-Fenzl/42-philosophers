/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/24 22:49:53 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if ((argc != 5 && argc != 6) || input_check(argv, &rules) == 1)
	{
		printf("ERROR: input not valid!\n");
		return (1);
	}
	printf("number of philosphers     %i\n", rules.amount_phil);
	printf("time to die               %li\n", rules.time_die);
	printf("time to eat               %li\n", rules.time_eat);
	printf("time to sleep             %li\n", rules.time_sleep);
	printf("time to must eat          %i\n", rules.must_eat);
	printf("---------------------------------\n");
	create(&rules);
	free(rules.philo);
	return (0);
}
