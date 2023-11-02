/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:48:10 by kfouad            #+#    #+#             */
/*   Updated: 2023/11/01 13:40:38 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_params prm;
	int i;

	i = 0;
	if (check_prms(ac, av) == -1)
		return (write(1, "error\n", 6), -1);
	fill_prms(&prm, av);
	if (!prm.max_meals)
		return (destroy(&prm), 0);
	prm.start_time = get_time();
	prm.ltm = get_time();
	while (i < prm.nb_philo)
	{
		pthread_create(&prm.ph[i].thread_id, NULL, action, &prm.ph[i]);
		pthread_detach(prm.ph[i].thread_id);
		i++;
	}
	main_thread(&prm);
	destroy(&prm);
	return (0);
}
