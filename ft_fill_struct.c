/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:04:38 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/28 19:37:51 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_fill_struct(char **argv)
{
	int				num;
	t_philo			*philo;
	t_data			*data;
	struct timeval	tv;

	num = ft_atoi(*argv);
	philo = (t_philo *)malloc(num * sizeof(t_philo));
	data = (t_data *)malloc(sizeof(t_data));
	data->num_philos = num;
	data->time_die = ft_atoi(argv[1]) * 1000;
	data->time_eat = ft_atoi(argv[2]) * 1000;
	data->time_sleep = ft_atoi(argv[3]) * 1000;
	// What if max_eat is < 0
	if (argv[4])
		data->max_eat = ft_atoi(argv[4]);
	else
		data->max_eat = -181;
	data->forks = (t_mutex *)malloc(num * sizeof(t_mutex));
	gettimeofday(&tv, NULL);
	data->now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (num-- > 0)
		philo[num].data = data;
	return (philo);
}
