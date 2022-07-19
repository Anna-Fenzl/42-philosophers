/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:16:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/19 14:37:02 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	ft_numcpy(int i, long res, char *p)
{
	long	tmp;

	while (p[i] != '\0')
	{
		tmp = res;
		if (p[i] >= '0' && p[i] <= '9')
		{
			res = res * 10 + p[i] - '0';
			i++;
		}
		else
			ft_error(1);
		if ((tmp < 0 && res > 0) || (tmp > 0 && res < 0))
			ft_error(2);
	}
	return (res);
}

long	atoi_check(const char *str)
{
	int				i;
	long			res;
	int				n;
	char			*p;

	i = 0;
	res = 0;
	n = 1;
	p = (char *)str;
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i + 1] == '\0')
			ft_error(1);
		if (p[i] == '-')
			n = -1;
		i++;
	}
	res = ft_numcpy(i, res, p);
	return (res * n);
}

int	print_feedback(t_philo *philo, char c)
{
	long	birth;

	birth = philo->data->birth;
	if (philo->death == false)
	{
		if (c == 't')
			printf("%ld %d is thinking\n", timestamp(birth), philo->number);
		else if (c == 's')
			printf("%ld %d is sleeping\n", timestamp(birth), philo->number);
		else if (c == 'e')
			printf("%ld %d is eating ---> %i * time\n", timestamp(birth),
				philo->number, philo->times_eaten);
		else if (c == 'r')
			printf("%ld %d has taken right fork\n", timestamp(birth), philo->number);
		else if (c == 'l')
			printf("%ld %d has taken left fork\n", timestamp(birth), philo->number);
		else if (c == 'd')
			printf("%ld %d ------->DIED\n", timestamp(birth), philo->number);
		return (0);
	}
	return (1);
}

// ----> im using EXIT !!!!
int	ft_error(int errorcode)
{
	printf("ERROR:	");
	if (errorcode == 0)
		printf("not the right amount of parameters!\n");
	else if (errorcode == 1)
		printf("not a valid number!\n");
	else if (errorcode == 2)
		printf("the number is not in the right range!\n");
	else if (errorcode == 3)
		printf("could not create thread!\n");
	else if (errorcode == 4)
		printf("could not join thread!\n");
	else if (errorcode == 5)
		printf("could not init mutex!\n");
	else if (errorcode == 6)
		printf("could not destroy mutex!\n");
	else if (errorcode == 7)
		printf("could not lock mutex!\n");
	else if (errorcode == 8)
		printf("could not unlock mutex!\n");
	exit (1);
}
