/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:07:49 by kfouad            #+#    #+#             */
/*   Updated: 2023/11/01 13:39:52 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t			thread_id;
	pthread_mutex_t		lock;
	int					id;
	int					meals;
	struct s_params		*prm;
}						t_philo;

typedef struct s_params
{
	unsigned long		tm_die;
	int					nb_philo;
	int					max_meals;
	unsigned long		tm_sleep;
	unsigned long		tm_eat;
	unsigned long long	start_time;
	unsigned long long	ltm;
	int					eaten;
	int					dead;
	int					current_philo;
	int					done;
	pthread_mutex_t		mutex;
	t_philo				ph[220];
}						t_params;

int						ft_atoi(const char *str);
int						eating(t_philo *philo);
void					main_thread(t_params *params);
void					*action(void *arg);
int						take_fork(t_philo *philo);
int						put_fork(t_philo *philo);
unsigned long long		get_time(void);
void					ft_usleep(unsigned long long msec);
void					fill_prms(t_params *prm, char **av);
int						check_prms(int ac, char **av);
void					destroy(t_params *prm);

#endif
