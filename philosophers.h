/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:08:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/04 16:23:12 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
	/*
	usleep --> suspends execution of the calling thread for (at least) usec microseconds.
		..
		unsigned int usecs;
		...
		usleep(usecs);
	*/
# include <sys/time.h>
	/*
	gettimeofday --> can get and set the time as well as a timezone
	
		int gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz);
		each of the parameters are structs in sys/time.h
		timezone usally is NULL cause obsolet
		return 0 on succes and -1 with errno in case of error
	*/
# include <pthread.h>
	/*
	pthread_create --> create a new thread
		int pthread_create(pthread_t *restrict thread,
						const pthread_attr_t *restrict attr,
						void *(*start_routine)(void *),
						void *restrict arg);

		Compile and link with "-pthread".
		On success, pthread_create() returns 0; on error, it returns an
		error number, and the contents of *thread are undefined.
	*/
#endif