/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/14 19:01:54 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// t_rules	*rules(void)
// {
// 	static t_rules	rules;

// 	return (&rules);
// }

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
		ft_error(0);
	input_check(argv, &rules);
	printf("amount_phil =  %i\n", rules.amount_phil);
	printf("time_die    =  %li\n", rules.time_die);
	printf("time_eat    =  %li\n", rules.time_eat);
	printf("time_sleep  =  %li\n", rules.time_sleep);
	printf("must_eat    = %i\n", rules.must_eat);
	printf("\n-------------------------\n");

	birth_philosophers(&rules);
	// system("leaks philo");
	return (0);
}
