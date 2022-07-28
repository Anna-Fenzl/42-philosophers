/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/28 16:39:14 by afenzl           ###   ########.fr       */
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
	rem_old_semaphores(&rules);
	create(&rules);
	free(rules.philo);
	return (0);
}
