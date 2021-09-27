/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:11:51 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/27 19:32:24 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_philo *philo)
{
	int			i;
	int			n;
	pthread_t	*t;

	i = 0;
	n = philo->data->num_philos;
	while (i < n)
	{
		t = &philo[i].philo;
		philo[i].id = i + 1;
		philo[i].eat_num = 0;
		philo[i].state = THINK;
		philo[i].last_eat = 0;
		if (i == n - 1)
			printf("philo %d, laast eat: %lu %d\n", i, philo[i].last_eat, philo[i].eat_num);
		if (pthread_create(t, NULL, &ft_pick_up_forks, (void *)(philo + i)))
			return (-1);
		i++;
	}
	return (0);
}
