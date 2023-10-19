/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:44 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/19 18:43:41 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_philo
{
	pthread_t		thread_id;
	pthread_mutex_t	lock;
	int				id;
	int				meals;
	struct s_params	*prm;
}	t_philo;

typedef struct s_params
{
    unsigned long   tm_die;
	int				nb_philo;
	int				max_meals;
	unsigned long	tm_sleep;
	unsigned long   tm_eat;
	t_philo			ph[220];
}t_params;

int	ft_atoi(const char *str);

#endif