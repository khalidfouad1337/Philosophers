/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:58:32 by kfouad            #+#    #+#             */
/*   Updated: 2023/11/01 13:41:12 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->prm->mutex);
	if (philo->prm->dead)
	{
		pthread_mutex_unlock(&philo->prm->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->prm->mutex);
	printf("%lld %d is eating\n", get_time() - philo->prm->start_time,
		   philo->id);
	pthread_mutex_lock(&philo->prm->mutex);
	philo->prm->current_philo = philo->id;
	pthread_mutex_unlock(&philo->prm->mutex);
	ft_usleep(philo->prm->tm_eat);
	pthread_mutex_lock(&philo->prm->mutex);
	philo->prm->eaten++;
	philo->meals++;
	pthread_mutex_unlock(&philo->prm->mutex);
	if (philo->prm->eaten == philo->prm->nb_philo)
	{
		pthread_mutex_lock(&philo->prm->mutex);
		philo->prm->eaten = 0;
		philo->prm->ltm = get_time();
		pthread_mutex_unlock(&philo->prm->mutex);
	}
	return (1);
}

int take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if (philo->id == philo->prm->nb_philo - 1)
		pthread_mutex_lock(&philo->prm->ph[0].lock);
	else
		pthread_mutex_lock(&philo->prm->ph[philo->id + 1].lock);
	pthread_mutex_lock(&philo->prm->mutex);
	if (philo->prm->dead)
	{
		pthread_mutex_unlock(&philo->prm->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->prm->mutex);
	printf("%lld %d has taken a fork\n", get_time() - philo->prm->start_time,
		   philo->id);
	return (1);
}

int put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->lock);
	if (philo->id == philo->prm->nb_philo - 1)
		pthread_mutex_unlock(&philo->prm->ph[0].lock);
	else
		pthread_mutex_unlock(&philo->prm->ph[philo->id + 1].lock);
	pthread_mutex_lock(&philo->prm->mutex);
	if (philo->prm->dead)
	{
		pthread_mutex_unlock(&philo->prm->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->prm->mutex);
	printf("%lld %d is sleeping\n", get_time() - philo->prm->start_time,
		   philo->id);
	if (philo->prm->dead)
		return (0);
	ft_usleep(philo->prm->tm_sleep);
	pthread_mutex_lock(&philo->prm->mutex);
	if (philo->prm->dead)
	{
		pthread_mutex_unlock(&philo->prm->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->prm->mutex);
	printf("%lld %d is thinking\n", get_time() - philo->prm->start_time,
		   philo->id);
	return (1);
}

void destroy(t_params *prm)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&prm->mutex);
	while (i < prm->nb_philo)
		pthread_mutex_destroy(&prm->ph[i++].lock);
}
