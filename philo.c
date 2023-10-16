/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:38 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/16 14:51:39 by kfouad           ###   ########.fr       */
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

int fill_param(int ac, char **av)
{
    int i = 0;
    t_global *params;
    params->nb_philo = ft_atoi(av[1]);
    params->tm_die = ft_atoi(av[2]);
    params->tm_eat = ft_atoi(av[3]);
    params->tm_sleep = ft_atoi(av[4]);
    params->max_meals = ft_atoi(av[5]);
    retuen (1);
}

int main(int ac, char **av)
{
    if (check_param(ac, av) == -1 && fill_param(ac, av))
        return(write(1, "error\n",6), -1);
        // printf("%lu and %lu\n", sizeof(useconds_t) , sizeof(unsigned long ));
    return (0);
}