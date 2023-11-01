/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:38 by kfouad            #+#    #+#             */
/*   Updated: 2023/11/01 13:04:35 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_prms(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (-1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (is_digit(av[i][j]) || (av[i][j] == '+' && is_digit(av[i][j
						+ 1])))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

void	fill_philo(t_params *prm)
{
	int	i;

	i = 0;
	pthread_mutex_init(&prm->mutex, NULL);
	while (i < prm->nb_philo)
	{
		pthread_mutex_init(&prm->ph[i].lock, NULL);
		prm->ph[i].id = i;
		prm->ph[i].prm = prm;
		prm->ph[i].meals = 0;
		i++;
	}
}

void	fill_prms(t_params *prm, char **av)
{
	prm->nb_philo = ft_atoi(av[1]);
	prm->tm_die = ft_atoi(av[2]);
	prm->tm_eat = ft_atoi(av[3]);
	prm->tm_sleep = ft_atoi(av[4]);
	if (av[5])
		prm->max_meals = ft_atoi(av[5]);
	else
		prm->max_meals = -1;
	prm->eaten = 0;
	prm->dead = 0;
	prm->done = 0;
	prm->current_philo = 0;
	fill_philo(prm);
}
