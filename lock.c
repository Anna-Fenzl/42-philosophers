/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:59:55 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/18 16:02:24 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_start(t_rules *rules)
{
	if (pthread_mutex_init(&(rules->wait_to_start), NULL) != 0)
		printf("couldnt init wait to start\n");
	if (pthread_mutex_lock(&(rules->wait_to_start)) != 0)
		printf("couldnt lock wait to start\n");
}

void	unlock_start(t_rules *rules)
{
	if (pthread_mutex_unlock(&(rules->wait_to_start)) != 0)
		printf("couldnt unlock wait_to_start\n");
	if (pthread_mutex_destroy(&(rules->wait_to_start)) != 0)
		printf("couldnt destroy wait_to_start\n");
}