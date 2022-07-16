/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:23:25 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/16 18:59:37 by afenzl           ###   ########.fr       */
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
