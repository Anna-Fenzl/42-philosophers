/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:34:21 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/07 16:29:19 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_t mutex;

void	routine()
{
	int	i;
	
	i = 0;
	while (i < 100)
	{
		i++;
	}
}

int	main(void)
{
	pthread_t	id[10];
	int			i;
	
	i = 0;
	while (i < 10)
	{
		if (pthread_create(&id[i], NULL, &routine, NULL)!= 0)
		{
			printf("ERROR: could not create\n");
			exit(1);	
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(id[i], NULL) != 0)
		{
			printf("ERROR\n");
			exit(1);
		}
		printf("thread %i has finsihed execution\n", i);
		i++;
	}
	return (0);
}