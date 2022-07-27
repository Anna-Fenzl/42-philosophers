/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:08:23 by afenzl            #+#    #+#             */
/*   Updated: 2022/07/27 14:53:49 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>

typedef struct s_rules	t_rules;

typedef struct s_philo
{
	int			number;
	int			times_eaten;
	long		limit;
	t_rules		*data;

}			t_philo;

typedef struct s_rules
{
	int					amount_phil;
	int					must_eat;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	long				birth;
	int					id_philo[201];
	t_philo				*philo;
	sem_t				*num_forks;
	sem_t				*death;
}			t_rules;

// time
void	sleep_ms(int ms);
long	get_current_time_ms(void);
long	timestamp(long birth);

// input
int		input_check(char **input, t_rules *rules);
long	atoi_check(const char *str);

void	create(t_rules *rules);
// philos
void	create_philos(t_rules *rules);
void	philo_start(t_philo *philo);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);

// utils
void	print_feedback(t_philo *philo, char c);
void	rem_old_semaphores(t_rules *rules);

// checker
void	check_if_dead(t_philo *philo);
void	must_eat(t_philo *philo);

#endif