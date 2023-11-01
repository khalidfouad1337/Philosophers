/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:18:55 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/16 17:30:25 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int i;
	int n;
	int na9is;

	i = 0;
	n = 0;
	na9is = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		na9is = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n * na9is);
}