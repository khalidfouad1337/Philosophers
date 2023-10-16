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

// typedef struct s_philo
// {
// 	int				id;
// 	struct s_global	*data;
// }	t_philo;

typedef struct s_global
{
    int             tm_die;
	int				nb_philo;
	int				max_meals;
	int				tm_sleep;
	int		        tm_eat;
}					t_global;

int	ft_atoi(const char *str);

#endif