/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/25 18:11:42 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// need to make them stop when one dies
int	main(int argc, char **argv)
{
	t_rules	rules;

	if ((argc != 5 && argc != 6) || input_check(argv, &rules) == 1)
	{
		printf("ERROR: input not valid!\n");
		return (1);
	}
	create(&rules);
	free(rules.philo);
	return (0);
}
