/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:08:31 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/27 17:09:11 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initiaze_mutex(p_mutex_t *mutex, int num_philos, p_mutex_t *print)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	pthread_mutex_init(print, NULL);
}
