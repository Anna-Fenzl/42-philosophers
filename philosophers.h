/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:08:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/21 13:53:33 by afenzl           ###   ########.fr       */
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
	bool				left;
	bool				right;
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
	pthread_t			id_philo[201];
	pthread_mutex_t		forks[200];
	pthread_mutex_t		lock;
	bool				death;

}			t_rules;

// time
void	sleep_ms(int ms);
long	get_current_time_ms(void);
long	timestamp(long birth);

// utils
void	ft_error(void);
void	unlock_forks(t_rules *rules);
void	unlock_both_forks(t_philo *philo);
int		print_feedback(t_philo *philo, char c);

// input
int		input_check(char **input, t_rules *rules);
long	atoi_check(const char *str);

void	create(t_rules *rules);

// philos
void	*work(void *data);
int		take_forks_and_eat(t_philo *philo);


// checker
int		check_if_dead(t_philo *philo);

#endif