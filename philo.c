/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:38 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/16 19:25:29 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int check_param(int ac ,char **av)
{
    int i;
    int j;
    i = 1;
    if(ac != 5 && ac != 6)
        return (-1);
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if(is_digit(av[i][j]) || (av[i][j] == '+' && is_digit(av[i][j+1])))
                j++;
            else
                return (-1);
        }
        i++;
    }
    return(1);
}

int ft_atoi_params(t_global *param, char **av)
{
    param->nb_philo = ft_atoi(av[1]);
    param->tm_die = ft_atoi(av[2]);
    param->tm_eat = ft_atoi(av[3]);
    param->tm_sleep = ft_atoi(av[4]);
    if(av[5])
        param->max_meals = ft_atoi(av[5]);
    else
        param->max_meals = -1;
    return (1);
}

int main(int ac, char **av)
{
    t_global param;
    if (check_param(ac, av) == -1)
        return(write(1, "error\n",6), -1);
    ft_atoi_params(&param, av);
    return (0);
}