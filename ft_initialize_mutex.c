/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:08:31 by akhalidy          #+#    #+#             */
/*   Updated: 2021/10/01 16:36:01 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initiaze_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(data->forks + i, NULL);
		pthread_mutex_init(&philo[i].is_eating, NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
}
