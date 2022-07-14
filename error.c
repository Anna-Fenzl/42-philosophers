/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:18:54 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/09 13:40:20 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(int errorcode)
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
	exit(1);
}
