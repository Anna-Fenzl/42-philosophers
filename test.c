/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:34:21 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/05 17:16:58 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_t mutex;

void	*routine(void *data)
{
	int *my_data;

	my_data = (int *)data;
	printf("hello from thread number %i\n", *my_data);
	return (data);
}

int	main(void)
{
	pthread_t	id[10];
	int			i;
	
	i = 0;
	while (i < 10)
	{
		if (pthread_create(&id[i], NULL, &routine, &i)!= 0)
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