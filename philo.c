/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:38 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/19 18:41:52 by kfouad           ###   ########.fr       */
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

int check_prms(int ac, char **av)
{
    int i;
    int j;
    i = 1;
    if (ac != 5 && ac != 6)
        return (-1);
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (is_digit(av[i][j]) || (av[i][j] == '+' && is_digit(av[i][j + 1])))
                j++;
            else
                return (-1);
        }
        i++;
    }
    return (1);
}

void    fill_philo(t_params *prm)
{
    int i;

    i = 0;
    while(i < prm->nb_philo)
    {
        pthread_mutex_init(&prm->ph[i].lock, NULL);
        prm->ph[i].id = i;
        prm->ph[i].meals = 0;
        prm->ph[i].prm = prm; 
        i++;
    }
}

void fill_prms(t_params *prm, char **av)
{
    prm->nb_philo = ft_atoi(av[1]);
    prm->tm_die = ft_atoi(av[2]) * 1000;
    prm->tm_eat = ft_atoi(av[3]) * 1000;
    prm->tm_sleep = ft_atoi(av[4]) * 1000;
    if (av[5])
        prm->max_meals = ft_atoi(av[5]);
    else
        prm->max_meals = -1;
    fill_philo(prm);
}

void*   action(void *arg)
{
    t_philo*    philo;

    philo = (t_philo*) arg;
    if (philo->id % 2 == 1)
        usleep(500);
    while(1)
    {
        pthread_mutex_lock(&philo->lock);
        if(philo->id == philo->prm->nb_philo - 1)
            pthread_mutex_lock(&philo->prm->ph[0].lock);
        else
            pthread_mutex_lock(&philo->prm->ph[philo->id + 1].lock);
        printf("%lld %d has taken a fork\n", philo->id);
        printf("%d is eating\n", philo->id);
        usleep(philo->prm->tm_eat);
        pthread_mutex_unlock(&philo->lock);
        if(philo->id == philo->prm->nb_philo - 1)
            pthread_mutex_unlock(&philo->prm->ph[0].lock);
        else
            pthread_mutex_unlock(&philo->prm->ph[philo->id + 1].lock);
        printf("%d is sleeping\n", philo->id);
        usleep(philo->prm->tm_sleep);
        printf("%d is thinking\n", philo->id);
        // printf("%d\n", philo->id);
        // sleep(1);
    }
    return (NULL);
}


int main(int ac, char **av)
{
    t_params prm;
    int     i;

    i = 0;
    if (check_prms(ac, av) == -1)
        return (write(1, "error\n", 6), -1);
    fill_prms(&prm, av);
    while(i < prm.nb_philo)
    {
       pthread_create(&prm.ph[i].thread_id, NULL, action, &prm.ph[i]);
       i++;
    }
    i = 0;
    while(i < prm.nb_philo)
    {
       pthread_join(prm.ph[i].thread_id, NULL);
       i++;
    }
    return (0);
}