/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:23:25 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/05 17:31:53 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	ft_numcpy(int i, long res, char *p)
{
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			res = res * 10 + p[i] - '0';
			i++;
			if (i > 11 && res > INT_MAX)
				ft_error(1);
		}
		else
			ft_error(1);
	}
	return (res);
}

int	atoi_check(const char *str)
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
	if ((res > INT_MAX && n == 1) || (res > 2147483648 && n == -1))
		ft_error(1);
	return (res * n);
}
