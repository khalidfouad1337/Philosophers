/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:53:01 by kfouad            #+#    #+#             */
/*   Updated: 2023/11/01 13:03:00 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(500);
	while (1)
	{
		if (!take_fork(philo))
			return (NULL);
		if (!eating(philo))
			return (NULL);
		if (!put_fork(philo))
			return (NULL);
		if (philo->prm->dead)
			return (NULL);
		if (philo->meals == philo->prm->max_meals)
		{
			pthread_mutex_lock(&philo->prm->mutex);
			philo->prm->done++;
			pthread_mutex_unlock(&philo->prm->mutex);
			return (NULL);
		}
	}
	return (NULL);
}

void	main_thread(t_params *params)
{
	while (1)
	{
		pthread_mutex_lock(&params->mutex);
		if (params->done == params->nb_philo)
		{
			pthread_mutex_unlock(&params->mutex);
			break ;
		}
		pthread_mutex_unlock(&params->mutex);
		pthread_mutex_lock(&params->mutex);
		if (get_time() - params->ltm >= params->tm_die)
		{
			printf("%lld %d dead\n", get_time() - params->start_time,
				params->current_philo);
			params->dead = 1;
			pthread_mutex_unlock(&params->mutex);
			break ;
		}
		pthread_mutex_unlock(&params->mutex);
	}
}
