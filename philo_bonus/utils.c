/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:16:14 by afenzl            #+#    #+#             */
/*   Updated: 2022/10/24 15:17:23 by afenzl           ###   ########.fr       */
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
			return (-1);
		if ((tmp < 0 && res > 0) || (tmp > 0 && res < 0))
			return (-1);
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
	while (p[i] == ' ' || p[i] == '\t')
		i++;
	if (p[i] == '-' || p[i] == '+')
	{
		if (p[i + 1] == '\0')
			return (-1);
		if (p[i] == '-')
			n = -1;
		i++;
	}
	res = ft_numcpy(i, res, p);
	return (res * n);
}

void	print_feedback(t_philo *philo, char c)
{
	long	birth;

	sem_wait(philo->data->print);
	birth = philo->data->birth;
	if (c == 't')
		printf("%ld %d is thinking\n", timestamp(birth), philo->number);
	else if (c == 's')
		printf("%ld %d is sleeping\n", timestamp(birth), philo->number);
	else if (c == 'e')
		printf("%s%ld %d is eating%s\n", GREEN, timestamp(birth),
			philo->number, RESET);
	else if (c == 'f')
		printf("%ld %d has taken a fork\n", timestamp(birth), philo->number);
	sem_post(philo->data->print);
}

void	rem_semaphores(t_rules *rules)
{
	sem_close(rules->death);
	sem_close(rules->num_forks);
	sem_close(rules->print);
	sem_unlink("not_existing");
	sem_unlink("/forks");
	sem_unlink("/print");
}

void	post_sems(sem_t *sem)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		sem_post(sem);
		i++;
	}
}
