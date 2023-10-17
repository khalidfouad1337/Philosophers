/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:44 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/16 19:39:41 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <time.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				meals;
	struct s_params	*prm;
}	t_philo;

typedef struct s_params
{
    int             tm_die;
	int				nb_philo;
	int				max_meals;
	int				tm_sleep;
	int		        tm_eat;
	t_philo			ph[220];
}t_params;

int	ft_atoi(const char *str);

#endif