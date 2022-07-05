/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:17:05 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/05 21:49:27 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void make_one_die(t_rules *rules)
{
	printf("hey, im %i phile\n", rules->num_phil);
	
}

int main(int argc, char **argv)
{
	t_rules rules;

	if (argc != 5 && argc != 6)
		ft_error(0);
	input_check(argv, &rules);
	if (rules.num_phil == 1)
		make_one_die(&rules);
	else
		birth_philosophers(&rules);
}