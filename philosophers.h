/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:08:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/19 14:26:43 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

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
		return 0 on success and -1 with errno in case of error
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

	pthread_detach --> when a detached thread terminates, its resources are automatically released back to the system without
						the need for another thread to join with the terminated thread
		int pthread_detach(pthread_t thread);
		
		On success, pthread_detach() returns 0; on error, it returns an error number.
	
	pthread_join --> pthread_join() function waits for the thread specified by thread to terminate.  If that thread has already terminated, then
						pthread_join() returns immediately.  The thread specified by thread must be joinable.
		int pthread_join(pthread_t thread, void **retval);
		
		On success, pthread_join() returns 0; on error, it returns an error number.
	
	pthread_mutex_init --> shall initialize the mutex referenced by mutex with attributes specified by attr.
							If attr is NULL, the default mutex attributes are used;
							the effect shall be the same as passing the address of a default mutex attributes object.
							Upon successful initialization, the state of the mutex becomes initialized and unlocked.
		int pthread_mutex_init(pthread_mutex_t *restrict mutex;
		
		If successful, the pthread_mutex_destroy() and pthread_mutex_init() functions shall return zero;
		otherwise, an error number shall be returned to indicate the error.

	pthread_mutex_destroy --> shall destroy the mutex object referenced by mutex; the mutex object becomes,
								in effect, uninitialized. An implementation may cause pthread_mutex_destroy() to set the object referenced by mutex to an invalid value.
								A destroyed mutex object can be reinitialized using pthread_mutex_init();
								the results of otherwise referencing the object after it has been destroyed are undefined.

								It shall be safe to destroy an initialized mutex that is unlocked.
								Attempting to destroy a locked mutex results in undefined behavior.
		int pthread_mutex_destroy(pthread_mutex_t *mutex);

		If successful, the pthread_mutex_destroy() and pthread_mutex_init() functions shall return zero;
		otherwise, an error number shall be returned to indicate the error.
	
	pthread_mutex_unlock --> n shall release the mutex object referenced by mutex.
							The manner in which a mutex is released is dependent upon the mutex's type attribute.
							If there are threads blocked on the mutex object referenced by mutex when pthread_mutex_unlock() is called,
							resulting in the mutex becoming available, the scheduling policy shall determine which thread shall acquire the mutex.
		int pthread_mutex_unlock(pthread_mutex_t *mutex);
	*/

typedef struct s_rules	t_rules;

typedef struct s_philo
{
	int					number;
	int					times_eaten;
	long				limit;
	bool				left;
	bool				right;
	bool				death;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		right_fork;
	t_rules				*data;

}			t_philo;

typedef struct s_rules
{
	int					amount_phil;
	int					must_eat;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	long				birth;
	t_philo				*philo;
	pthread_t			id_philo[201];
	pthread_mutex_t		forks[200];
	pthread_mutex_t		wait_to_start;

}			t_rules;

// time
void	sleep_ms(int ms);
long	get_current_time_ms(void);
long	timestamp(long birth);

// utils
void	ft_error(int errorcode);
void	lock_start(t_rules *rules);
void	unlock_start(t_rules *rules);
void	unlock_forks(t_rules *rules);
int		print_feedback(t_philo *philo, char c);

// input
void	input_check(char **input, t_rules *rules);
long	atoi_check(const char *str);

void	create(t_rules *rules);

// philos
void	*work(void *data);

// checker
int		check_if_dead(t_philo *philo);
void	*waiter(void *data);

#endif