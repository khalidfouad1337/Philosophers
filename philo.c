/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:37:38 by kfouad            #+#    #+#             */
/*   Updated: 2023/10/22 14:48:24 by kfouad           ###   ########.fr       */
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
    pthread_mutex_init(&prm->mutex, NULL);
    while(i < prm->nb_philo)
    {
        pthread_mutex_init(&prm->ph[i].lock, NULL);
        prm->ph[i].id = i;
        prm->ph[i].prm = prm; 
        prm->ph[i].meals = 0; 
        i++;
    }
}

void fill_prms(t_params *prm, char **av)
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

unsigned long long  get_time(void)
{
    struct timeval	tm;
    gettimeofday(&tm, NULL);
    return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

void    ft_usleep(unsigned long long msec)
{
    unsigned long long start;
   
    start = get_time();
    while (1)
    {
        if (get_time() - start >= msec)
            break ;
        usleep(500);
    }
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
        printf("%lld %d has taken a fork\n", get_time() - philo->prm->start_time,philo->id);
        printf("%lld %d is eating\n", get_time() - philo->prm->start_time, philo->id);
        philo->prm->current_philo = philo->id;
        ft_usleep(philo->prm->tm_eat);
        philo->prm->eaten++;
        if (philo->prm->eaten == philo->prm->nb_philo)
        {
            philo->prm->eaten = 0;
            philo->prm->ltm = get_time();
        }
        philo->meals++;
        pthread_mutex_unlock(&philo->lock);
        if(philo->id == philo->prm->nb_philo - 1)
            pthread_mutex_unlock(&philo->prm->ph[0].lock);
        else
            pthread_mutex_unlock(&philo->prm->ph[philo->id + 1].lock);
        printf("%lld %d is sleeping\n", get_time() - philo->prm->start_time, philo->id);
        ft_usleep(philo->prm->tm_sleep);
        printf("%lld %d is thinking\n", get_time() - philo->prm->start_time, philo->id);
        if (philo->meals == philo->prm->max_meals)
        {
            philo->prm->done++;
            return (NULL);
        }
    }
    return (NULL);
}

void    main_thread(t_params *params)
{
    while (1)
    {
        if (params->done == params->nb_philo)
            break ;
        if (get_time() - params->ltm >= params->tm_die)
        {
            printf("%lld %d dead\n", get_time() - params->start_time, params->current_philo);
            params->dead = 1;
            break ;
        }
    }
}

int main(int ac, char **av)
{
    t_params prm;
    int     i;

    i = 0;
    if (check_prms(ac, av) == -1)
        return (write(1, "error\n", 6), -1);
    fill_prms(&prm, av);
    prm.start_time = get_time();
    prm.ltm = get_time();
    while(i < prm.nb_philo)
    {
       pthread_create(&prm.ph[i].thread_id, NULL, action, &prm.ph[i]);
       i++;
    }
    main_thread(&prm);
    return (0);
}