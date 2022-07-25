/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:08:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/24 19:41:07 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_rules	t_rules;

typedef struct s_philo
{
	int					number;
	int					times_eaten;
	long				limit;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
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
	pthread_t			id_philo[200];
	pthread_mutex_t		forks[200];
	pthread_mutex_t		lock;
	bool				death;

}			t_rules;

// time
void	sleep_ms(int ms);
long	get_current_time_ms(void);
long	timestamp(long birth);

// utils
void	unlock_both_forks(t_philo *philo);
int		print_feedback(t_philo *philo, char c);

// input
int		input_check(char **input, t_rules *rules);
long	atoi_check(const char *str);

// main
void	create_philos(t_rules *rules);
void	join_threads(t_rules *rules);

// philos
void	*work(void *data);
int		die_alone(t_philo *philo);
int		who_takes_forks(t_philo *philo);
int		eat(t_philo *philo);

// checker
int		check_if_dead(t_philo *philo);
int		must_eat_checker(t_philo *philo);

#endif